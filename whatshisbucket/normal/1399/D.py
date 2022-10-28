t=int(input())
for _ in range(t):
    n=int(input())
    a=input()
    zeros=set()
    ones=set()
    tot=0
    out=[]
    for i in range(n):
        if a[i]=="0":
            if len(ones)==0:
                tot+=1
                zeros.add(tot)
                out.append(tot)
            else:
                for guy in ones:
                    x=guy
                    break
                ones.remove(x)
                zeros.add(x)
                out.append(x)
        else:
            if len(zeros)==0:
                tot+=1
                ones.add(tot)
                out.append(tot)
            else:
                for guy in zeros:
                    x=guy
                    break
                zeros.remove(x)
                ones.add(x)
                out.append(x)
    print(tot)
    print(" ".join([str(guy) for guy in out]))