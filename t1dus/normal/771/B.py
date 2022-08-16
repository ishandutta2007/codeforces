n,k = map(int,input().split())
a = list(input().split())

mem = []
mem2 = []
for i in 'abcdefghijklmnopqrstuvwxyz':
    mem.append(i)
    mem.append('a'+i)
    mem2.append('b'+i)
    mem2.append('c'+i)
dp = [-1]*(n)
c = 0
c2 = 0
for i in range(len(a)):
    if a[i] == "NO":
        if dp[i] == -1:
            dp[i] = mem2[c2]
            dp[i+k-1] = mem2[c2]
        else:    
            dp[i+k-1] = dp[i]
        c2 += 1
    else:
        for j in range(i,i+k):
            if (dp[j] == -1):
                dp[j] = mem[c]
                c += 1

for i in range(n):
    if dp[i] == -1:
        dp[i] = 'a'
            
for i in dp:
    print(i[0].upper()+i[1:],end=' ')