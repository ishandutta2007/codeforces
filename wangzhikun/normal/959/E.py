ans = 0
n = int(input())
k = 2**63
lpre = [0]
for i in range(50):
    lpre.append(lpre[-1]*2+2**i)
lmax = -1
for i in range(42,-1,-1):
    #print(i)
    if n&2**i:
        ans+=lpre[i]
        if lmax != -1:
            ans+=2**lmax
        lmax = i
print(ans)