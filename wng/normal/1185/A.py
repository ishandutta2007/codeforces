a,b,c,d=[int(k) for k in input().split(" ")]

a,b,c=sorted([a,b,c])

res=max(0,d-b+a)+max(0,d-c+b)

print(res)