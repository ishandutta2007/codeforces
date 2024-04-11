t=int(input())
for _ in range(t):
    n=int(input())
    print("Q",n//2," ".join([str(i+1) for i in range(n//2*2)]))
    s1=input()
    print("Q",n-n//2-1," ".join([str(i+2) for i in range((n-n//2-1)*2)]))
    s2=input()
    con=[0]*(n-1)
    for i in range(n//2):
        con[2*i]=int(s1[i])
    for i in range(n-n//2-1):
        con[2*i+1]=int(s2[i])
    ints=[]
    start=1
    end=1
    for guy in con:
        if guy==0:
            ints.append((start,end))
            start,end=end+1,end+1
        else:
            end+=1
    ints.append((start,end))
    k=len(ints)
    things=[]
    for i in range(k-2):
        if i%4==0 or i%4==1:
            things.append(i)
            things.append(i+2)
    print("Q",len(things)//2," ".join([str(ints[guy][0]) for guy in things]))
    s1=input()
    others=[]
    for i in range(k-2):
        if i%4==2 or i%4==3:
            others.append(i)
            others.append(i+2)
    print("Q",len(others)//2," ".join([str(ints[guy][0]) for guy in others]))
    s2=input()
    skips=[0]*(k-2)
    for i in range(len(things)//2):
        skips[things[2*i]]=int(s1[i])
    for i in range(len(others)//2):
        skips[others[2*i]]=int(s2[i])
    cols=[0,1]
    for i in range(k-2):
        if skips[i]==1:
            cols.append(cols[-2])
        else:
            cols.append(2*(cols[-1]+cols[-2])%3)
    a=[]
    b=[]
    c=[]
    for i in range(k):
        if cols[i]==0:
            for guy in range(ints[i][0],ints[i][1]+1):
                a.append(guy)
        elif cols[i]==1:
            for guy in range(ints[i][0],ints[i][1]+1):
                b.append(guy)
        else:
            for guy in range(ints[i][0],ints[i][1]+1):
                c.append(guy)
    print("A",len(a),len(b),len(c))
    print(*a)
    print(*b)
    print(*c)