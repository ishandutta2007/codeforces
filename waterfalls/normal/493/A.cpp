#include <cstdio>
#include <map>

using namespace std;

int main() {
    map<int,int> fouls;
    char home[26];
    char away[26];
    int n;
    scanf(" %s %s %d",&home,&away,&n);
    int t,m;
    char team;
    char card;
    for (int i=0;i<n;i++) {
        scanf("%d %c%d %c",&t,&team,&m,&card);
        if (team=='a') m+=100;
        if (fouls.count(m)==0 && card=='y') fouls[m] = 1;
        else if (fouls[m]>2) continue;
        else {
            if (team=='h') printf("%s %d %d\n",home,m,t);
            else printf("%s %d %d\n",away,m-100,t);
            fouls[m] = 3;
        }
    }

    return 0;
}