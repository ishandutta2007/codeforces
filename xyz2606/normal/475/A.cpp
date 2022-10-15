#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
using namespace std;
char ans[6][35] = {
"+------------------------+",
"|#.#.#.#.#.#.#.#.#.#.#.|D|)",
"|#.#.#.#.#.#.#.#.#.#.#.|.|",
"|#.......................|",
"|#.#.#.#.#.#.#.#.#.#.#.|.|)",
"+------------------------+"
};
int main()
{
    int n;
    scanf("%d", &n);
    int i(1);
    while(n and i <= 4) {
        ans[i++][1] = 'O';
        n--;
    }
    i = 1;


    int j(3);
    while(n) {
        n--;
        ans[i][j] = 'O';
        if(i == 1)
            i = 2;
        else if(i == 2)
            i = 4;
        else if(i == 4) {
            i = 1; j+= 2;
        }
    }
    for(int i(0); i < 6; i++)
        printf("%s\n", ans[i]);
    return 0;
}