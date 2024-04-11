
n,m=[int(k) for k in raw_input().split(" ")]
a=[int(k) for k in raw_input().split(" ")]
b=[int(k) for k in raw_input().split(" ")]

res=[]

for k in a:
    maxjk=max([j*k for j in b])
    if res is None or maxjk<res:
        res+=[maxjk]

print sorted(res)[-2]