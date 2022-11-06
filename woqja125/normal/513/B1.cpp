#include<stdio.h>
#include<deque>
int main()
{
    int n;
    long long m;
    scanf("%d%I64d", &n, &m);
    int i;
    int c = 0;
    std::deque<int> Q;
    Q.push_back(n);
    m--;
    for(i=n-1; i>=1; i--)
    {
        if(m%2 == 0) Q.push_front(i);
        else Q.push_back(i);
        m /= 2;
    }
    for(i=0; i<Q.size(); i++)printf("%d ", Q[i]); 
    return 0;
}