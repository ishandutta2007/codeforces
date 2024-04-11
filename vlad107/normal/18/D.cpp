#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <vector>

#define MAXX 2011
#define MAXN 5011
#define bigint std::vector<int>
#define BASE 1000000000

struct Point{
    int ss,ff,tt;
    bool was;
};

bigint st2[MAXX+5],res;
std::vector<Point>w;
int n,gues[MAXN+5],x[MAXN+5],last[MAXX+5];

bigint BigSum(bigint a,bigint b){
    int carry=0,dl=std::max(a.size(),b.size());
    for (int q=0;q<dl;q++){
        if (q==a.size())a.push_back(0);
        a[q]+=carry+(q<b.size()?b[q]:0);
        if (a[q]>=BASE){
            carry=1;
            a[q]-=BASE;
        }else carry=0;
    }
    if (carry)a.push_back(carry);
    return a;
}

bool cmp(Point a,Point b){
    return a.tt>b.tt;
}

bool cross(int x1,int y1,int x2,int y2){
    if (x1>=x2&&x1<=y2)return true;
    if (y1>=x2&&y1<=y2)return true;
    if (x2>=x1&&x2<=y1)return true;
    if (y2>=x1&&y2<=y1)return true;
    return false;
}

int main(){
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    st2[0].push_back(1);
    for (int i=1;i<MAXX;i++)
        st2[i]=BigSum(st2[i-1],st2[i-1]);
    scanf("%d\n",&n);
    for (int i=0;i<n;i++){
        char ch=getchar();
        while (ch!='w'&&ch!='s')ch=getchar();
        gues[i]=(ch=='w');
        while (ch!=' ')ch=getchar();
        scanf("%d",&x[i]);
    }
    memset(last,-1,sizeof(last));
    for (int i=0;i<n;i++)
        if (gues[i])
            last[x[i]]=i;
        else{
            if (last[x[i]]<0)continue;
            Point q;
            q.ss=last[x[i]];
            q.ff=i;
            q.tt=x[i];
            q.was=false;
            w.push_back(q);
        }
    std::sort(w.begin(),w.end(),cmp);
    res.push_back(0);
    for (int i=0;i<w.size();i++){
        bool ok=true;
        for (int j=0;j<i;j++)
            if (w[j].was&&cross(w[j].ss,w[j].ff,w[i].ss,w[i].ff)){
                ok=false;break;
            }
        if (!ok)continue;
        w[i].was=true;
        res=BigSum(res,st2[w[i].tt]);
    }
    printf("%d",res.back());
    for (int i=res.size()-2;i>=0;i--)
        printf("%09d",res[i]);
    printf("\n");
}