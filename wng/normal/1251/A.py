t=[int(k) for k in input().split(" ")][0]

for k in range(t):
    s=input()
    ss=set()
    k=0
    n=len(s)
    while k<n:
        kk=k
        while kk<n and s[kk]==s[k]:
            kk+=1
        if (kk-k)%2:
            ss.add(s[k])
        k=kk
    print("".join(sorted(list(ss))))