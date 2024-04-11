#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> vals;

long long cnt[100100];

int in[100100];

long long sum[100100];

int main()
{
    int N;
    long long K;
    scanf("%d%I64d",&N,&K);
    for(int i=0;i<N;i++)
    {
        scanf("%d",in+i);
        vals.push_back(in[i]);
    }
    sort(vals.begin(),vals.end());
    vals.erase(unique(vals.begin(),vals.end()),vals.end());
    for(int i=0;i<N;i++)
    {
        cnt[distance(vals.begin(),lower_bound(vals.begin(),vals.end(),in[i]))+1]++;
    }
    sum[0]=0;
    for(int i=1;i<=vals.size();i++)
    {
        sum[i]=sum[i-1]+cnt[i];
    }
    int M=vals.size();
    for(int s=1;s<=M;s++)
    {
        if(K>cnt[s]*sum[M])
        {
            K-=cnt[s]*sum[M];
            continue;
        }
        int l;
        for(int t=1;t<=M;t++)
        {
            if(K>cnt[s]*cnt[t])
            {
                K-=cnt[s]*cnt[t];
                continue;
            }
            l=t;
            break;
        }
        printf("%d %d\n",vals[s-1],vals[l-1]);
        break;
    }
    return 0;
}