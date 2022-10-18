#include<bits/stdc++.h>

using namespace std;

const int inf=1000;

int main()
{
    int n;
    scanf("%i\n",&n);
    multiset<char> a;
    int k=0;
    for(int i=1;i<n;i++)
    {
        char c,C;
        scanf("%c%c",&c,&C);
        C+='a'-'A';
        a.insert(c);
        multiset<char>::iterator it=a.find(C), e=a.end();
        if(it==e)
            k++;
        else
            a.erase(it);
    }
    printf("%i\n",k);
}