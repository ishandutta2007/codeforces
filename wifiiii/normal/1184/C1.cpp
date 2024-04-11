#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define forii for(int i=1;i<=n;++i)
#define forji for(int j=1;j<=n;++j)
#define forjj for(int j=1;j<=m;++j)
#define forij for(int i=1;i<=m;++i)

int cnt1[55],cnt2[55],x[55],y[55];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=4*n+1;++i) {
        cin>>x[i]>>y[i];
    }
    for(int x1=0;x1<=50;++x1)
    {
        for(int x2=x1+1;x2<=50;++x2)
        {
            for(int y1=0;y1<=50;++y1)
            {
                for(int y2=y1+1;y2<=50;++y2)
                {
                    int cnt = 0;
                    for(int i=1;i<=4*n+1;++i) {
                        if(x[i]<=x2&&x[i]>=x1&&y[i]<=y2&&y[i]>=y1&&(x[i]==x1||x[i]==x2||y[i]==y1||y[i]==y2))
                            cnt++;
                    }
                    if(cnt==4*n)
                    {
                        for(int i=1;i<=4*n+1;++i) {
                            if(x[i]<=x2&&x[i]>=x1&&y[i]<=y2&&y[i]>=y1&&(x[i]==x1||x[i]==x2||y[i]==y1||y[i]==y2))
                                continue;
                            cout<<x[i]<<" "<<y[i]<<endl;
                            return 0;
                        }
                    }
                    
                }
            }
        }
    }
    
}