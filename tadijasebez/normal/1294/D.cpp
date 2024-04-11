#include <bits/stdc++.h>
using namespace std;
const int N=400050;
int las[N];
bool was[N];
int main(){
    int n,x;
    scanf("%i %i",&n,&x);
    for(int i=0;i<x;i++)las[i]=i;
    for(int ptr=0;n--;){
        int y;
        scanf("%i",&y);
        y%=x;
        if(las[y]<N)
            was[las[y]]=1,
            las[y]+=x;
        while(was[ptr])ptr++;
        printf("%i\n",ptr);
    }
    return 0;
}