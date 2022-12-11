#include <bits/stdc++.h>

using namespace std;

const int N=1e5+10;

int n;
long long a[N],b[N];

priority_queue <long long> q;
int main(){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];

        long long sum=0;
        for(int i=1;i<=n;i++){
                q.push(-(a[i]+sum));
                long long decay=0;
                while (!q.empty()&&-q.top()<=sum+b[i]){
                        decay+=-q.top()-sum;
                        q.pop();
                }
                sum+=b[i];
                cout<<q.size()*b[i]+decay<<" ";
        }
}