n=int(raw_input())
sizes=["M"]+["X"*k+"S" for k in range(4)]+["X"*k+"L" for k in range(4)]
d=dict(zip(sizes,[[0,0] for i in range(len(sizes))]))
for i in range(n):
    d[raw_input()][0]+=1
for i in range(n):
    d[raw_input()][1]+=1

print n-sum([min(k) for k in d.values()])