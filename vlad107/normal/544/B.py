n,k=map(int,raw_input().split())
a,s=['LS'[(i+j)%2] for i in range(n) for j in range(n)],(n*n+1)/2
for _ in range(s-k): a[a.index('L')]='S'
print(["YES\n"+"\n".join("".join(a[i*n:i*n+n]) for i in range(n)),
       "NO"][s<k])