n=[int(k) for k in raw_input().split(" ")][0]

res=0

for i in range(n):
    res=max(res,sum([int(k) for k in raw_input().split(" ")]))

print res