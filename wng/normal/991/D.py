#[int(k) for k in raw_input().split(" ")]

s=[]
s+=[raw_input()]
s+=[raw_input()]

A=[[1,0,0,0]] #all occupied, 1st free, 2nd free, all free
S=[[0,0,0,0]] #max number of b placed
n=len(s[0])
for i in range(n):
    olda=A[-1][:]
    olds=S[-1][:]
    A+=[[0,0,0,0]]
    S+=[[0,0,0,0]]
    if s[0][i]=="0" and s[1][i]=="0":
        A[-1][3]+=sum(olda)
        A[-1][0]+=sum(olda)-olda[0]
        A[-1][1]+=olda[3]
        A[-1][2]+=olda[3]
        S[-1][3]=max(S[-1][3],max(olds))
        if A[-1][0]:
            S[-1][0]=max(S[-1][0],max(olds[1:])+1)
        if olda[3]:
            S[-1][1]=max(S[-1][1],olds[3]+1)
        if olda[3]:
            S[-1][2]=max(S[-1][2],olds[3]+1)
    elif s[0][i]=="0" and s[1][i]=="X":
        A[-1][1]+=sum(olda)
        A[-1][0]+=olda[3]
        S[-1][1]=max(S[-1][1],max(olds))
        if olda[3]:
            S[-1][0]=max(S[-1][0],olds[3]+1)
    elif s[0][i]=="X" and s[1][i]=="0":
        A[-1][2]+=sum(olda)
        A[-1][0]+=olda[3]
        S[-1][2]=max(S[-1][2],max(olds))
        if olda[3]:
            S[-1][0]=max(S[-1][0],olds[3]+1)
    else:
        A[-1][0]+=sum(olda)
        S[-1][0]=max(S[-1][0],max(olds))

#print S
#print A
print max(S[-1])