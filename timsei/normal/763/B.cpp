
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
const int  maxn = 1e5+10;  
int x1[maxn],x2[maxn],y1[maxn],y2[maxn];  
int main()  
{  
    int n;  
    while(scanf("%d",&n)!=EOF)  
    {  
        for(int i=0;i<n;++i)  
            scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);  
        puts("YES");  
        for(int i=0;i<n;++i)  
        {  
            int x=abs(min(x1[i],x2[i]));  
            int y=abs(min(y1[i],y2[i]));  
            if(x%2==1 && y%2==1)  
                puts("1");  
            else if(x%2==1 && y%2==0)  
                puts("2");  
            else if(x%2==0 && y%2==1)  
                puts("3");  
            else if(x%2==0 && y%2==0)  
                puts("4");  
        }  
    }  
    return 0;  
}