#include<bits/stdc++.h>

#define stop1 scanf("%*c")
#define stop2 stop1,stop1

using namespace std;

int arr[97];

void fill(int l,int r,int v)
{
    for(int i=l;i<=r;i++)
        arr[i]=v;
}

void fill(int l,int r)
{
    for(int i=l;i<=r;i++)
        arr[i]=i;
}

void add(int l,int r)
{
    set<int>s;
    for(int i=1;i<=26;i++)
        s.insert(i);
    int a=r-l+1;
    for(int i=l-a;i<=r-a;i++)
        s.erase(arr[i]);
    for(int i=l;i<=r;i++)
        arr[i]=*s.begin(),s.erase(s.begin());
}

int prov(int l,int r)
{
    set<int>s;
    for(int i=l;i<=r;i++)
        s.insert(arr[i]);
    return s.size();
}

int main()
{
    int a,b,l,r;
    scanf("%d%d%d%d",&a,&b,&l,&r);
    int d=2*(a+b);
    if(r-l+1>=d)
        return printf("%d",max(a+1,2*a-b)),0;
    r-=(l-1)/d*d;
    l-=(l-1)/d*d;
    int m=26;
    fill(1,a);
    for(int i=1;i<=26;i++)
        for(int j=1;j<=26;j++)
            for(int k=1;k<=26;k++)
            {
                fill(a+1,a+b,i);
                add(a+b+1,2*a+b);
                fill(2*a+b+1,2*a+2*b,j);
                add(2*a+2*b+1,3*a+2*b);
                fill(3*a+2*b+1,3*a+3*b,k);
                add(3*a+3*b+1,4*a+3*b);
                fill(4*a+3*b+1,4*a+4*b,arr[4*a+3*b]);
                /*for(int i=1;i<=l-1;i++)
                    printf("%2d ",arr[i]);
                printf("| ");
                for(int i=l;i<=r;i++)
                    printf("%2d ",arr[i]);
                printf("| ");
                for(int i=r+1;i<=4*(a+b);i++)
                    printf("%2d ",arr[i]);*/
                int p=prov(l,r);
                //printf("- %2d\n",p);
                m=min(m,p);
                //stop1;
            }
    printf("%d",m);
    //stop2;
}