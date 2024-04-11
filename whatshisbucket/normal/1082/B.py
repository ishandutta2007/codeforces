import math
n=int(input())
a=input()
lens=[]
currlen=1
for i in range(n-1):
    if a[i+1]==a[i]:
        currlen+=1
    else:
        lens.append(currlen)
        currlen=1
lens.append(currlen)
if a[0]=="G":
    if len(lens)<3:
        print(lens[0])
    elif len(lens)<5:
        if lens[1]==1:
            print(lens[0]+lens[2])
        else:
            print(max(lens[0],lens[2])+1)
    else:
        indivbest=0
        consecbest=0
        for i in range(math.ceil(len(lens)/2)):
            indivbest=max(indivbest,lens[2*i]+1)
            if i>0:
                if lens[2*i-1]==1:
                    consecbest=max(consecbest,lens[2*i]+lens[2*i-2]+1)
        print(max(indivbest,consecbest))
else:
    if len(lens)<2:
        print(0)
    elif len(lens)<4:
        print(lens[1])
    elif len(lens)<6:
        if lens[2]==1:
            print(lens[1]+lens[3])
        else:
            print(max(lens[1],lens[3])+1)
    else:
        indivbest=0
        consecbest=0
        for i in range(len(lens)//2):
            indivbest=max(indivbest,lens[2*i+1]+1)
            if i>0:
                if lens[2*i]==1:
                    consecbest=max(consecbest,lens[2*i+1]+lens[2*i-1]+1)
        print(max(indivbest,consecbest))