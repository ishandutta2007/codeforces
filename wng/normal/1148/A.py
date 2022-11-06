a,b,c=[int(k) for k in input().split(" ")]

m=min(a,b)
M=min(m+1,max(a,b))

res=m+M+2*c

print(res)