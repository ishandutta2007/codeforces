n,m=[int(k) for k in raw_input().split(" ")]
e=[]
for i in range(m):
    e+=[[int(k) for k in raw_input().split(" ")]+[i+1]]
    
se=sorted(e)

pe=0
bestsched=["0"]*(se[0][0]-1)

i=se[0][0]
exp=[]
ts=False
exams=[-1]*(n+1)
numberexams=[-1]*(n+1)
possible=True
for k in se:
    if exams[k[1]]>=0:
        possible=False
    exams[k[1]]=k[2]
    numberexams[k[1]]=k[3]
    
while i<=n:
    while pe<m and se[pe][0]<=i:
        exp+=[se[pe][1:]]
        pe+=1
        ts=True
    if ts:
        exp=sorted(exp)
    if exams[i]>0:
        possible=False
    if exams[i]==0:
        bestsched+=[str(m+1)]
    if exams[i]<0:
        if exp:
            exams[exp[0][0]]-=1
            bestsched+=[str(exp[0][2])]
            if not exams[exp[0][0]]:
                exp=exp[1:]
        else:
            bestsched+=["0"]
    i+=1

if not possible:
    print -1
else:
    print " ".join(bestsched)