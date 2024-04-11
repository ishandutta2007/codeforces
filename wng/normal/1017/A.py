n=[int(k) for k in raw_input().split(" ")][0]
t=[]
for i in range(n):
    t+=[sum([int(k) for k in raw_input().split(" ")])]

z=sorted(range(n),key=lambda x: (-t[x],x))

myk=[k for k in range(n) if z[k]==0][0]

print myk+1