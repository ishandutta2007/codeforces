n=int(raw_input())
d={}
poss=set()
for i in range(n):
    d[i]=[int(k) for k in raw_input().split(" ")]
    np=set(d[i])
    for k in d[i]:
        np|=set([int(str(k)+str(j)) for j in poss])
        np|=set([int(str(j)+str(k)) for j in poss])
    #print i,poss
    #print np
    poss|=np

for i in range(1,1001):
    if i not in poss:
        print i-1
        break