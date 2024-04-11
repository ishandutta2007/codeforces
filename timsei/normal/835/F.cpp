#include<bits/stdc++.h>
#define LL long long
#define INF 1000000000000000LL
#define MAXN 200010
using namespace std;
#define int long long
struct node
{
    int begin,end,value,next;
}edge[MAXN*2];
struct NODE
{
    int left,right;LL mx1,mxi1,mx2,mxi2,Mx1,Mxi1,Mx2,Mxi2;
}tree[8*MAXN];
int cnt,Head[MAXN],pd,cc[MAXN],lcc,U[MAXN],V[MAXN],W[MAXN],wz,p[MAXN*2];
LL sum[MAXN*2],dd[MAXN],len[MAXN],dis[MAXN];
bool vis[MAXN],vv[MAXN*2];
int read()
{
    int s=0,fh=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')fh=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){s=s*10+(ch-'0');ch=getchar();}
    return s*fh;
}
void addedge(int bb,int ee,int vv)
{
    edge[++cnt].begin=bb;edge[cnt].end=ee;edge[cnt].value=vv;edge[cnt].next=Head[bb];Head[bb]=cnt;
}
void addedge1(int bb,int ee,int vv)
{
    addedge(bb,ee,vv);addedge(ee,bb,vv);
}
void Find_circle(int u,int fa)
{
    int i,v;
    vis[u]=true;
    for(i=Head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].end;
        if(v==fa)continue;
        if(vis[v]==false)Find_circle(v,u);
        else
        {
            if(pd==-1){pd=v;cc[++lcc]=i;return;}
        }
        if(pd!=-1)
        {
            cc[++lcc]=i;
            if(pd==u)pd=-1;
            return;//!!!!!!!!!!!!!!!!!!!!!!!!!
        }
    }
}
void dfs(int u,int fa)
{
    int i,v;
    for(i=Head[u];i!=-1;i=edge[i].next)
    {
        v=edge[i].end;
        if(v==fa||vv[i]==true||vv[i^1]==true)continue;
        dd[v]=dd[u]+edge[i].value;
        if(dd[v]>dd[wz])wz=v;
        dfs(v,u);
    }
}
NODE Merge(NODE L,NODE R)
{
    NODE M;
    M=(NODE){L.left,R.right,-INF,-1,-INF,-1,-INF,-1,-INF,-1};
    if(L.mx1>M.mx1){M.mx2=M.mx1;M.mxi2=M.mxi1;M.mx1=L.mx1;M.mxi1=L.mxi1;}
    //**************!!!!!!!!!!!!!!!!!!!!!!!!!!**************
    //M.mx2=M.mx1;M.mxi2=M.mxi1;,,
    //Test#1 ~ Test#20,Extra Test#13 WA,Extra Test#13
    else if(L.mx1>M.mx2){M.mx2=L.mx1;M.mxi2=L.mxi1;}
    if(L.mx2>M.mx1){M.mx2=M.mx1;M.mxi2=M.mxi1;M.mx1=L.mx2;M.mxi1=L.mxi2;}
    else if(L.mx2>M.mx2){M.mx2=L.mx2;M.mxi2=L.mxi2;}

    if(R.mx1>M.mx1){M.mx2=M.mx1;M.mxi2=M.mxi1;M.mx1=R.mx1;M.mxi1=R.mxi1;}
    else if(R.mx1>M.mx2){M.mx2=R.mx1;M.mxi2=R.mxi1;}
    if(R.mx2>M.mx1){M.mx2=M.mx1;M.mxi2=M.mxi1;M.mx1=R.mx2;M.mxi1=R.mxi2;}
    else if(R.mx2>M.mx2){M.mx2=R.mx2;M.mxi2=R.mxi2;}


    if(L.Mx1>M.Mx1){M.Mx2=M.Mx1;M.Mxi2=M.Mxi1;M.Mx1=L.Mx1;M.Mxi1=L.Mxi1;}
    else if(L.Mx1>M.Mx2){M.Mx2=L.Mx1;M.Mxi2=L.Mxi1;}
    if(L.Mx2>M.Mx1){M.Mx2=M.Mx1;M.Mxi2=M.Mxi1;M.Mx1=L.Mx2;M.Mxi1=L.Mxi2;}
    else if(L.Mx2>M.Mx2){M.Mx2=L.Mx2;M.Mxi2=L.Mxi2;}

    if(R.Mx1>M.Mx1){M.Mx2=M.Mx1;M.Mxi2=M.Mxi1;M.Mx1=R.Mx1;M.Mxi1=R.Mxi1;}
    else if(R.Mx1>M.Mx2){M.Mx2=R.Mx1;M.Mxi2=R.Mxi1;}
    if(R.Mx2>M.Mx1){M.Mx2=M.Mx1;M.Mxi2=M.Mxi1;M.Mx1=R.Mx2;M.Mxi1=R.Mxi2;}
    else if(R.Mx2>M.Mx2){M.Mx2=R.Mx2;M.Mxi2=R.Mxi2;}
    return M;
}
void Build(int k,int l,int r)
{
    tree[k].left=l;tree[k].right=r;
    if(l==r)
    {
        tree[k].mx1=dis[p[l]]+sum[l];tree[k].mxi1=l;
        tree[k].mx2=-INF;tree[k].mxi2=-1;
        tree[k].Mx1=dis[p[l]]-sum[l];tree[k].Mxi1=l;
        tree[k].Mx2=-INF;tree[k].Mxi2=-1;
        return;
    }
    int mid=(l+r)/2;
    Build(k*2,l,mid);
    Build(k*2+1,mid+1,r);
    tree[k]=Merge(tree[k*2],tree[k*2+1]);
}
NODE Query(int k,int ql,int qr)
{
    if(ql<=tree[k].left&&tree[k].right<=qr)return tree[k];
    int mid=(tree[k].left+tree[k].right)/2;
    if(qr<=mid)return Query(k*2,ql,qr);
    else if(ql>mid)return Query(k*2+1,ql,qr);
    else return Merge(Query(k*2,ql,mid),Query(k*2+1,mid+1,qr));
}
main()
{
    //freopen("in","r",stdin);
    int N,i,wz1,NN,ii;
    LL ans=0LL,MAX;
    N=read();
    memset(Head,-1,sizeof(Head));cnt=1;
    for(i=1;i<=N;i++){U[i]=read();V[i]=read();W[i]=read();addedge1(U[i],V[i],W[i]);}
    memset(cc,0,sizeof(cc));lcc=0;pd=-1;
    memset(vis,false,sizeof(vis));
    Find_circle(1,0);
    /**********************************************
    for(i=1;i<=lcc;i++)
    {
        printf("%d %d\n",edge[cc[i]].begin,edge[cc[i]].end);
    }
    return 0;
    **********************************************/
    memset(vv,false,sizeof(vv));//()
    for(i=1;i<=lcc;i++)vv[cc[i]]=vv[cc[i]^1]=true;
    
    memset(dis,0,sizeof(dis));//dis[i]ii
    memset(len,0,sizeof(len));//len[i]i
    for(i=1;i<=lcc;i++)
    {
        wz=0;dd[edge[cc[i]].begin]=0LL;dfs(edge[cc[i]].begin,0);wz1=wz;dis[edge[cc[i]].begin]=dd[wz];
        wz=0;dd[wz1]=0LL;dfs(wz1,0);len[edge[cc[i]].begin]=dd[wz];
    }

    memset(p,0,sizeof(p));//p[](,)
    memset(sum,0,sizeof(sum));//sum[]
    NN=lcc*2;
    ii=0;for(i=lcc;i>=1;i--){ii++;p[ii]=p[lcc+ii]=edge[cc[i]].begin;}//,
    ii=0;for(i=lcc;i>=1;i--){ii++;sum[ii+1]=sum[ii]+(LL)edge[cc[i]].value;}
    for(i=lcc;i>=2;i--){ii++;sum[ii+1]=sum[ii]+(LL)edge[cc[i]].value;}

    Build(1,1,NN);//

    MAX=0LL;
    for(i=1;i<=NN;i++)MAX=max(MAX,len[p[i]]);//()
    ii=0;ans=INF;
    for(i=lcc;i>=1;i--)
    {
        ii++;
        NODE Get=Query(1,ii+1,ii+1+lcc-1);
        if(Get.mxi1!=Get.Mxi1)ans=min(ans,max(MAX,Get.mx1+Get.Mx1));
        else
        {
            ans=min(ans,max(MAX,max(Get.mx1+Get.Mx2,Get.mx2+Get.Mx1)));
        }
    }
    printf("%lld",(int)ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}