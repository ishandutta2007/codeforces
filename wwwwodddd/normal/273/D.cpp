#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
int MOD = 1000000007; 
int res[2][2][160][160];
int newRes[2][2][160][160];
int main()
{ 
    int height;
    int width;
	cin>>height>>width;
    int totalRes = 0; 
    for (int row = 0; row < height; ++row) { 
		memset(newRes,0,sizeof newRes);
        for (int firstDecreased = 0; firstDecreased < 2; ++firstDecreased) 
            for (int lastDecreased = 0; lastDecreased < 2; ++lastDecreased) 
                for (int firstCol = 0; firstCol < width; ++firstCol) 
                    for (int lastCol = firstCol; lastCol < width; ++lastCol) { 
                        int cur = res[firstDecreased][lastDecreased][firstCol][lastCol]; 
                        if (cur == 0) continue; 
                        for (int newFirstDecreased = firstDecreased; newFirstDecreased < 2; ++newFirstDecreased) 
                            for (int newLastDecreased = lastDecreased; newLastDecreased < 2; ++newLastDecreased) { 
                                int newFirstCol; 
                                if (newFirstDecreased == 0) 
                                    newFirstCol = firstCol; 
                                else if (firstDecreased == 0) 
                                    newFirstCol = firstCol + 1; 
                                else 
                                    newFirstCol = firstCol; 
                                int newLastCol; 
                                if (newLastDecreased == 0) 
                                    newLastCol = lastCol; 
                                else if (lastDecreased == 0) 
                                    newLastCol = lastCol - 1; 
                                else 
                                    newLastCol = lastCol; 
                                if (newFirstCol > newLastCol) 
                                    continue; 
                                int* arr = newRes[newFirstDecreased][newLastDecreased][newFirstCol]; 
                                arr[newLastCol] += cur; 
                                if (arr[newLastCol] >= MOD) arr[newLastCol] -= MOD; 
                            } 
                    } 

        for (int firstDecreased = 0; firstDecreased < 2; ++firstDecreased) 
            for (int lastDecreased = 0; lastDecreased < 2; ++lastDecreased) { 
                int (*arr)[160] = newRes[firstDecreased][lastDecreased]; 
                if (firstDecreased == 0 && lastDecreased == 1) { 
                    { 
                        int lastDelta = lastDecreased == 0 ? 1 : -1; 
                        int lastMin = lastDelta == 1 ? 0 : width - 1; 
                        int lastMax = lastDelta == 1 ? width : -1; 
                        for (int lastCol = lastMin; lastCol != lastMax; lastCol += lastDelta) { 
                            for (int firstCol = 0; firstCol <= lastCol; ++firstCol) { 
                                int cur = arr[firstCol][lastCol]; 
                                if (cur == 0) continue; 
                                int newLastCol = lastCol + lastDelta; 
                                if (newLastCol >= firstCol && newLastCol < width) { 
                                    arr[firstCol][newLastCol] += cur; 
                                    if (arr[firstCol][newLastCol] >= MOD) arr[firstCol][newLastCol] -= MOD; 
                                } 
                            } 
                        } 
                    } 
                    { 
                        int firstDelta = firstDecreased == 0 ? -1 : 1; 
                        int firstMin = firstDelta == 1 ? 0 : width - 1; 
                        int firstMax = firstDelta == 1 ? width : -1; 
                        for (int firstCol = firstMin; firstCol != firstMax; firstCol += firstDelta) { 
                            for (int lastCol = firstCol; lastCol < width; ++lastCol) { 
                                int cur = arr[firstCol][lastCol]; 
                                if (cur == 0) continue; 
                                int newFirstCol = firstCol + firstDelta; 
                                if (newFirstCol >= 0 && newFirstCol <= lastCol) { 
                                    arr[newFirstCol][lastCol] += cur; 
                                    if (arr[newFirstCol][lastCol] >= MOD) arr[newFirstCol][lastCol] -= MOD; 
                                } 
                            } 
                        } 
                    } 
                } else { 
                    { 
                        int firstDelta = firstDecreased == 0 ? -1 : 1; 
                        int firstMin = firstDelta == 1 ? 0 : width - 1; 
                        int firstMax = firstDelta == 1 ? width : -1; 
                        for (int firstCol = firstMin; firstCol != firstMax; firstCol += firstDelta) { 
                            for (int lastCol = firstCol; lastCol < width; ++lastCol) { 
                                int cur = arr[firstCol][lastCol]; 
                                if (cur == 0) continue; 
                                int newFirstCol = firstCol + firstDelta; 
                                if (newFirstCol >= 0 && newFirstCol <= lastCol) { 
                                    arr[newFirstCol][lastCol] += cur; 
                                    if (arr[newFirstCol][lastCol] >= MOD) arr[newFirstCol][lastCol] -= MOD; 
                                } 
                            } 
                        } 
                    } 
                    { 
                        int lastDelta = lastDecreased == 0 ? 1 : -1; 
                        int lastMin = lastDelta == 1 ? 0 : width - 1; 
                        int lastMax = lastDelta == 1 ? width : -1; 
                        for (int lastCol = lastMin; lastCol != lastMax; lastCol += lastDelta) { 
                            for (int firstCol = 0; firstCol <= lastCol; ++firstCol) { 
                                int cur = arr[firstCol][lastCol]; 
                                if (cur == 0) continue; 
                                int newLastCol = lastCol + lastDelta; 
                                if (newLastCol >= firstCol && newLastCol < width) { 
                                    arr[firstCol][newLastCol] += cur; 
                                    if (arr[firstCol][newLastCol] >= MOD) arr[firstCol][newLastCol] -= MOD; 
                                } 
                            } 
                        } 
                    } 
                } 
            } 

        for (int firstCol = 0; firstCol < width; ++firstCol) { 
            for (int lastCol = firstCol; lastCol < width; ++lastCol) { 
                    newRes[0][0][firstCol][lastCol] += 1; 
                    if (newRes[0][0][firstCol][lastCol] >= MOD) newRes[0][0][firstCol][lastCol] -= MOD; 
            }  
        } 
		memcpy(res,newRes,sizeof newRes);
        for (int firstDecreased = 0; firstDecreased < 2; ++firstDecreased) 
            for (int lastDecreased = 0; lastDecreased < 2; ++lastDecreased) 
                for (int firstCol = 0; firstCol < width; ++firstCol) 
                    for (int lastCol = firstCol; lastCol < width; ++lastCol) { 
                        totalRes += res[firstDecreased][lastDecreased][firstCol][lastCol]; 
                        if (totalRes >= MOD) totalRes -= MOD; 
                    } 
    } 
    cout << totalRes;
    return 0;
}