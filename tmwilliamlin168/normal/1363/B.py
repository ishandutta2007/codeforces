t=int(input())
for _ in [0]*t:s=input();print(min(s[:i].count('01'[k])+s[i:].count('10'[k])for k in [0,1]for i in range(len(s)+1)))