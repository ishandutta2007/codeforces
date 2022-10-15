#include<cstring>

#include<cstdio>

#include<algorithm>
#include<map>

using namespace std;
map<int, int> mpx, mpy;

int mn, inf = 0x7fffffff, n, m, nI, nII, x, y, hshx[100001], hshy[100001], xl, xr, yl, yr, *p, ans[100001], nvp, totx, toty, pos[100001];
pair<int, int> vpool[200000 * 17], norm;

struct reca

{

    int xl, xr, yl, yr, z, i;

} a[100001];

bool operator < (const reca & a, const reca & b)

{

    return a.z < b.z;

}

struct recq

{

    int x, y, v;

} q[100001];

bool operator < (const recq & a, const recq & b)

{

    return a.x < b.x;

}

struct SegII

{

    int l, r, mn;

    pair<int, int> * v;

    int getmin();
    SegII *s[2];

    int del();

} IIpool[200000 * 17];


struct SegI

{

    int l, r, mn;

    SegII * root;

    int getmin();
    SegI *s[2];

    void del();

} Ipool[200000], *root;

SegII * build(pair<int, int> * v, int le, int ri)

{

    SegII * p = &IIpool[++nII];

    p->l = le; p->r = ri;

    p->v = v;

    if(le == ri)

    {

        p->mn = v[le].second;

        p->s[0] = p->s[1] = 0;

    }else

    {

        p->s[0] = build(v, le, (le + ri) / 2);

        p->s[1] = build(v, (le + ri) / 2 + 1, ri);

        p->mn = min(p->s[0]->mn, p->s[1]->mn);

    }

    return p;

}

SegI * build(int le, int ri, int vl, int vr)

{

    SegI * p = &Ipool[++nI];

    p->l = le; p->r = ri;

    for(int i = vl; i <= vr; i++)

    {

        vpool[nvp + i - vl] = make_pair(q[i].y, q[i].v);

    }

    sort(vpool + nvp, vpool + nvp + vr - vl + 1);

    p->root = build(vpool + nvp - 1, 1, vr - vl + 1);

    nvp += vr - vl + 1;

    p->mn = inf;

    p->s[0] = p->s[1] = 0;

    if(le != ri)

    {

        int mid = vl;

        while(mid != vr and q[mid + 1].x <= (le + ri) / 2) mid++;

        if(q[mid].x <= (le + ri) / 2) p->s[0] = build(le, (le + ri) / 2, vl, mid), p->mn = min(p->mn, p->s[0]->mn);

        if(mid + 1 <= vr and q[mid + 1].x > (le + ri) / 2) p->s[1] = build((le + ri) / 2 + 1, ri, mid + 1, vr), p->mn = min(p->mn, p->s[1]->mn);

    }

    return p;

}

int SegII::getmin()

{
    //printf("II %d %d %d %d\n", l, r, yl, yr);

    if(yl > v[r].first or yr < v[l].first)

        return inf;

    else if(yl <= v[l].first and v[r].first <= yr)

        return mn;

    else 

        return min(s[0]->getmin(), s[1]->getmin());

}

int SegI::getmin()

{
    //printf("I %d %d %d %d %d\n", l, r, xl, xr, root);

    if(xl > r or xr < l)

        return inf;

    else if(xl <= l and r <= xr)

        return root->getmin();

    else

        return min(s[0]?s[0]->getmin():inf, s[1]?s[1]->getmin():inf);

}

int SegII::del()

{

    if(v[l] > norm or norm > v[r])

        return mn;

    else if(l == r)

        return mn = inf;

    else

        return mn = min(s[0]->del(), s[1]->del());

}

void SegI::del()

{

    if(x < l or r < x)

        ;

    else if(l == r)

        root->del();

    else
    {

        root->del();
        for(int i = 0; i < 2; i++) if(s[i]) s[i]->del();
    }

}

int main()

{

    scanf("%d", &n);

    for(int i = 1; i <= n; i++)

    {

        scanf("%d%d%d%d%d", &a[i].xl, &a[i].xr, &a[i].yl, &a[i].yr, &a[i].z);

        a[i].i = i;

    }

    sort(a + 1, a + 1 + n);//by z decreasing

    scanf("%d", &m);

    for(int i = 1; i <= m; i++)

    {

        scanf("%d%d", &q[i].x, &q[i].y);

        q[i].v = i;

        mpx[q[i].x]; mpy[q[i].y];

    }

    totx = toty = 0;

    for(map<int, int>::iterator itr = mpx.begin(); itr != mpx.end(); itr++)

    {

        itr->second = ++totx;

        hshx[totx] = itr->first;

    }

    for(map<int, int>::iterator itr = mpy.begin(); itr != mpy.end(); itr++)

    {

        itr->second = ++toty;

        hshy[toty] = itr->first;

    }

    for(int i = 1; i <= m; i++)

    {

        q[i].x = mpx[q[i].x];

        q[i].y = mpy[q[i].y];

    }

    sort(q + 1, q + 1 + m);//by x

    for(int i = 1; i <= m; i++) pos[q[i].v] = i;

    root = build(1, totx, 1, m);
    memset(ans, 0, sizeof(ans));
    //for(int i = 1; i <= totx; i++) printf("%d ", hshx[i]); printf("\n");
    //for(int i = 1; i <= toty; i++) printf("%d ", hshy[i]); printf("\n");
    

    for(int i = 1; i <= n; i++)

    {

        a[i].xl = lower_bound(hshx + 1, hshx + totx + 1, a[i].xl) - hshx;

        int * p = lower_bound(hshx + 1, hshx + totx + 1, a[i].xr);
            if(p != hshx + totx + 1 and *p == a[i].xr) a[i].xr = p - hshx; else a[i].xr = p - hshx - 1;

        if(a[i].xl > a[i].xr) continue;

        a[i].yl = lower_bound(hshy + 1, hshy + toty + 1, a[i].yl) - hshy;

        p = lower_bound(hshy + 1, hshy + toty + 1, a[i].yr);

        if(p != hshy + toty + 1 and *p == a[i].yr) a[i].yr = p - hshy; else a[i].yr = p - hshy - 1;

        if(a[i].yl > a[i].yr) continue;

        xl = a[i].xl; xr = a[i].xr;

        yl = a[i].yl; yr = a[i].yr;
        //printf("%d %d %d %d\n", xl, xr, yl, yr);

        mn = root->getmin();
        //printf("mn = %d\n", mn);

        if(mn == inf)

        {

        }else

        {

            ans[mn] = a[i].i;

            y = q[pos[mn]].y;

            x = q[pos[mn]].x;
            norm = make_pair(y, mn);
            //printf("%d %d\n", x, y);

            root->del();

        }

    }

    for(int i = 1; i <= m; i++) printf("%d\n", ans[i]);

    fclose(stdin);

    return 0;

}