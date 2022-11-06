
n=int(raw_input())
a=[int(k)-1 for k in raw_input().split(" ")]

nbmax= [0,0,0,0]

for k in a:
    if k:
        nbmax[1]=max(nbmax[1]+1,nbmax[0]+1)
        nbmax[3]=max(nbmax[3]+1,nbmax[2]+1)
    else:
        nbmax[0]+=1
        nbmax[2]=max(nbmax[1]+1,nbmax[2]+1)

print max(nbmax)