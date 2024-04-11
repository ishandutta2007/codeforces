#include <bits/stdc++.h>

using namespace std;

int N;
int A[100];
vector<string> ans;

void gen(vector<int> a)
{
    string s(N, '0');
    for(auto& it: a)
        s[it]='1';
    ans.push_back(s);
}

int main()
{
    scanf("%d", &N);
    int m=100;
    for(int i=0; i<N; i++)
        scanf("%d", A+i), m=min(m, A[i]);
    for(int x=m; x>=1; x--)
    {
        set<pair<int, int>> t;
        int s=0;
        for(int i=0; i<N; i++)
        {
            s+=A[i]-x;
            if(A[i]-x>0)
                t.insert({A[i]-x, i});
        }
        if(s==0)
        {
            printf("%d\n", x);
            printf("0\n");
            return 0;
        }
        if(s==1)
            continue;
        ans.clear();
        set<pair<int, int>>::iterator it, pit, ppit;
        if(s%2==1)
        {
            if(t.size()==1)
                goto bad;
            if(t.size()==2)
                goto bad;
            it=--t.end();
            pit=it; --pit;
            ppit=pit, --ppit;
            gen({it->second, pit->second, ppit->second});
            if(it->first>1)
                t.insert({it->first-1, it->second});
            if(pit->first>1)
                t.insert({pit->first-1, pit->second});
            if(ppit->first>1)
                t.insert({ppit->first-1, ppit->second});
            t.erase(it);
            t.erase(pit);
            t.erase(ppit);
        }
        while(!t.empty())
        {
            if(t.size()==1)
                goto bad;
            it=--t.end();
            pit=it; --pit;
            gen({it->second, pit->second});
            if(it->first>1)
                t.insert({it->first-1, it->second});
            if(pit->first>1)
                t.insert({pit->first-1, pit->second});
            t.erase(it);
            t.erase(pit);
        }
        printf("%d\n", x);
        printf("%d\n", (int)ans.size());
        for(auto& s: ans)
            printf("%s\n", s.c_str());
        return 0;
        bad:;
    }
    printf("0\n");
    printf("%d\n", (N-1)*100);
    for(int i=1; i<N; i++)
    {
        string s(N, '0');
        s[i-1]='1';
        s[i]='1';
        for(int j=0; j<100; j++)
            printf("%s\n", s.c_str());
    }
    return 0;
}