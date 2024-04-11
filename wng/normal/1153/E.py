from sys import stdout

n=int(input())

rowimpairs=[]

for i in range(n-1):
    print("? {} {} {} {}".format(i+1,1,i+1,n))
    stdout.flush()
    res=int(input())
    if (res%2):
        rowimpairs+=[i]
if len(rowimpairs)==1:
    rowimpairs+=[n-1]

    
colimpairs=[]

for i in range(n-1):
    print("? {} {} {} {}".format(1,i+1,n,i+1))
    stdout.flush()
    res=int(input())
    if (res%2):
        colimpairs+=[i]
if len(colimpairs)==1:
    colimpairs+=[n-1]


if len(colimpairs) and len(rowimpairs):
    hl=min(rowimpairs),min(colimpairs)
    print("? {} {} {} {}".format(1,1,hl[0]+1,hl[1]+1))
    stdout.flush()
    res=int(input())
    if (res%2):
        print("! {} {} {} {}".format(hl[0]+1,hl[1]+1,max(rowimpairs)+1,max(colimpairs)+1))
    else:
        print("! {} {} {} {}".format(hl[0]+1,max(colimpairs)+1,max(rowimpairs)+1,hl[1]+1))
else:
    #find which row
    if len(colimpairs):
        i=-1
        mc=min(colimpairs)
        ta=512
        while ta:
            totry=i+ta
            if totry<n:
                print("? {} {} {} {}".format(1,1,totry+1,mc+1))
                res=int(input())
                if not (res%2):
                    i+=ta
            ta>>=1
        i+=1
        print("! {} {} {} {}".format(i+1,colimpairs[0]+1,i+1,colimpairs[1]+1))
    if len(rowimpairs):
        i=-1
        mc=min(rowimpairs)
        ta=512
        while ta:
            totry=i+ta
            if totry<n:
                print("? {} {} {} {}".format(1,1,mc+1,totry+1))
                res=int(input())
                if not (res%2):
                    i+=ta
            ta>>=1
        i+=1
        print("! {} {} {} {}".format(rowimpairs[0]+1,i+1,rowimpairs[1]+1,i+1))
    assert(len(rowimpairs)+len(colimpairs))
                      
stdout.flush()