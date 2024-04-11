#include <bits/stdc++.h>
using namespace std;
const int Maxn=500005;
int n,m,q,a[Maxn],cnt[Maxn],ct,out[Maxn],tot,rk[Maxn];
long long tmp[Maxn],now[Maxn],all;
vector <int> Ve[Maxn];
struct quest
{
	int id;
	long long x;
	bool operator < (const quest &tmp) const
	{
		return x<tmp.x;
	}
}Q[Maxn];

//Splay

struct node
{
    int val,siz,cnt;
    node* son[2],*fa;
}*root;
void create(node* &t)
{
    t=new(node);
    t->val=t->siz=0;
    t->son[0]=t->son[1]=t->fa=NULL;
}
bool get_son(node* t)
{
    return t->fa->son[1]==t;
}
void update(node* t)
{
    t->siz=t->cnt;
    if(t->son[0]!=NULL) t->siz+=t->son[0]->siz;
    if(t->son[1]!=NULL) t->siz+=t->son[1]->siz;
}
void rotate(node* t)
{
    node *fa=t->fa,*gf=fa->fa;
    if(gf!=NULL)
    {
        bool s=get_son(fa);
        gf->son[s]=t;
    }
    else root=t;
    bool ss=get_son(t);
    fa->son[ss]=t->son[!ss];
    if(t->son[!ss]!=NULL) t->son[!ss]->fa=fa;
    t->son[!ss]=fa;
    fa->fa=t;
    t->fa=gf;
    if(gf!=NULL) update(gf);
    update(fa),update(t);
}
void splay(node* t,node* goal=NULL)
{
    while(t->fa!=goal)
    {
        node* fa=t->fa,*gf=fa->fa;
        if(gf==goal)
            rotate(t);
        else
        {
            if(get_son(fa)^get_son(t))
                rotate(t),rotate(t);
            else
                rotate(fa),rotate(t);
        }
    }
}
node* insert(int val)
{
    node* tmp;
    if(root==NULL)
    {
        create(root);
        root->val=val;
        root->cnt=root->siz=1;
        return root;
    }
    else
    {
        for(node* t=root;t!=NULL;t=t->son[val>=t->val])
        {
            if(t->val==val)
            {
                t->cnt++;
                if(t->fa!=NULL)
                    update(t->fa);
                splay(t);
                update(t);
                tmp=t;
                break;
            }
            if(t->son[val>=t->val]==NULL)
            {
                bool s=val>=t->val;
                create(t->son[s]);
                t->son[s]->val=val;
                t->son[s]->cnt=1;
                t->son[s]->siz=1;
                t->son[s]->fa=t;
                update(t);
                tmp=t->son[s];
                break;
            }
        }
    }
    splay(tmp);
    return tmp;
}
node* find_kth(int k)
{
    for(node* t=root;t!=NULL;)
    {
        int tmp=0;
        if(t->son[0]!=NULL)
            tmp+=t->son[0]->siz;
        if(k>tmp&&k<=tmp+t->cnt) return t;
        if(tmp<k&&t->son[1]!=NULL) k-=tmp+t->cnt,t=t->son[1];
        else t=t->son[0];
    }
}



int main()
{
//	freopen("D.in","r",stdin);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),cnt[a[i]]++;
	for(int i=1;i<=m;i++) rk[i]=i;
	sort(rk+1,rk+1+m,[](int x,int y){return cnt[x]<cnt[y];});
	for(int i=1;i<=q;i++)
		scanf("%lld",&Q[i].x),Q[i].id=i;
	sort(Q+1,Q+1+q);
	insert(rk[1]);
	tot=1;
	for(int i=1;i<=q;i++)
	{
		Q[i].x-=n+1;
		while(tot<m&&all+(long long)tot*(cnt[rk[tot+1]]-cnt[rk[tot]])<=Q[i].x)
		{
			all+=(long long)tot*(cnt[rk[tot+1]]-cnt[rk[tot]]);
			insert(rk[++tot]);
		}
		Q[i].x=(Q[i].x-all)%tot+1;
		out[Q[i].id]=find_kth(Q[i].x)->val;
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",out[i]);
	return 0;
}