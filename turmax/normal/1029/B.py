a=int(input())
b=[int(i) for i in input().split()]
t=[]
i=0
while(i<len(b)):
    j=i
    m=1
    while(j<len(b)-1):
        if(b[j+1]<=(b[j]*2)):
            j+=1
            m+=1
            i+=1
        else:
            break
    t.append(m)
    i+=1
print(max(t))