#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back

vector <pair<int, pair<int, int> > > vec;
map<string, int> mp1;
vector <int> zhat;

const ll SZPER = 100100*64;

int all = 0, t1[100100*64], t2[100100*64], sz1 = 1, sz2 = 1, root1[100100*64], lstver1 = 1, lstver2 = 1;
int L1[SZPER], L2[SZPER], R1[SZPER], R2[SZPER], root2[SZPER];

int vcopy1(int v)
{
    ++lstver1;
    t1[lstver1] = t1[v];
    L1[lstver1] = L1[v];
    R1[lstver1] = R1[v];
    return lstver1;
}
int vcopy2(int v)
{
    ++lstver2;
    t2[lstver2] = t2[v];
    L2[lstver2] = L2[v];
    R2[lstver2] = R2[v];
    return lstver2;
}

int get1(int v, int l, int r, int tl, int tr){
    if (l > r || tl > r || l > tr || v == 0)
        return 0;
    if (tl <= l && r <= tr)
        return t1[v];
    int mid = (l+r)>>1;
    return get1(L1[v], l, mid, tl, tr) + get1(R1[v], mid+1, r, tl, tr);
}

int get2(int v, int l, int r, int pos){
    if (v == 0)
        return 0;
    if (l == r)
        return t2[v];
    int mid = (l+r)>>1;
    if (pos <= mid){
        return get2(L2[v], l, mid, pos);
    } else {
        return get2(R2[v], mid+1, r, pos);
    }
}

void update1(int v, int l, int r, int pos, int x){
    if (l == r){
        t1[v] += x;
        return;
    }
    int mid = (l+r)>>1;
    if (pos <= mid){
        L1[v] = vcopy1(L1[v]);
        update1(L1[v], l, mid, pos, x);
    } else {
        R1[v] = vcopy1(R1[v]);
        update1(R1[v], mid+1, r, pos, x);
    }
    t1[v] = t1[L1[v]] + t1[R1[v]];
}
void update2(int v, int l, int r, int pos, int x){
    if (l == r){
        t2[v] = x;
        return;
    }
    int mid = (l+r)>>1;
    if (pos <= mid){
        L2[v] = vcopy2(L2[v]);
        update2(L2[v], l, mid, pos, x);
    } else {
        R2[v] = vcopy2(R2[v]);
        update2(R2[v], mid+1, r, pos, x);
    }
}

 main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int tt;
    cin >> tt;
    while(sz1 < 1e9)
        sz1+=sz1;
    while(sz2 < 100000)
        sz2 += sz2;
    root1[0] = root2[0] = 1;
    for (int i = 1; i <= tt; i++){
        int type, v, num;
        string s, s1;
        cin >> s;
        if (s[0] != 'u')
        cin >> s1;
        if (mp1[s1] == 0){
            all++;
            mp1[s1] = all;
        }
        v = mp1[s1];
        if (s[0] == 's'){
            type = 0;
        }
        if (s[0] == 'r')
            type = 1;
        if (s[0] == 'q')
            type = 2;
        if (s[0] == 'u'){
            type = 3;
        }

        if (type == 0){
            cin >> num;
            root1[i] = vcopy1(root1[i-1]);
            root2[i] = vcopy2(root2[i-1]);
            int prior = get2(root2[i], 1, sz2, v);
            if (prior != 0){
                update1(root1[i], 1, sz1, prior, -1);
            }
            update1(root1[i], 1, sz1, num, 1);
            update2(root2[i], 1, sz2, v, num);
        }
        if (type == 1){
            root1[i] = vcopy1(root1[i-1]);
            root2[i] = vcopy2(root2[i-1]);
            int prior = get2(root2[i], 1, sz2, v);
            if (prior != 0){
                update1(root1[i], 1, sz1, prior, -1);
            }
            update2(root2[i], 1, sz2, v, 0);
        }
        if (type == 2){
            root1[i] = vcopy1(root1[i-1]);
            root2[i] = vcopy2(root2[i-1]);
            int prior = get2(root2[i], 1, sz2, v);
            if (prior == 0){
                cout << -1 << endl;
                continue;
            }
            cout << get1(root1[i], 1, sz1, 1, prior-1) << endl;
        }
        if (type == 3){
            cin >> num;
            //cout << "kek " << i-num  << endl;
            root1[i] = vcopy1(root1[i-num-1]);
            root2[i] = vcopy2(root2[i-num-1]);
        }
    }


}