n,A =[int(k) for k in raw_input().split(" ")]
c=[int(k) for k in raw_input().split(" ")]

nba=0
dicOK={}
dicOK[A]=0
for i in range(n):
    if c[i] not in dicOK and dicOK[A]==0:
        dicOK[c[i]]=0
    if c[i] in dicOK:
        if c[i]==A:
            dicOK[A]+=1
        else:
            if dicOK[c[i]]<dicOK[A]:
                del dicOK[c[i]]
            else:
                dicOK[c[i]]+=1

res=-1
for k in dicOK.keys():
    if k!=A and dicOK[k]>=dicOK[A]:
        res=k
        break
if res==-1 and dicOK[A]==0:
    res=A+1
print res