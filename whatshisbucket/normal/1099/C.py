s=input()
n=int(input())
a,b=s.count("*"),s.count("?")
c=len(s)-a-b
if n<c-a-b:
    print("Impossible")
elif a==0 and n>c:
    print("Impossible")
elif n<=c:
    removed=0
    index=0
    while index<len(s):
        if s[index]=="*" or s[index]=="?":
            if removed<c-n:
                s=s[:index-1]+s[index+1:]
                index-=1
                removed+=1
            else:
                s=s[:index]+s[index+1:]
        else:
            index+=1
    print(s)
else:
    contin=True
    while contin:
        contin=False
        seen=False
        for i in range(len(s)):
            if s[i]=="*":
                if not seen:
                    seen=True
                else:
                    s=s[:i-1]+s[i+1:]
                    contin=True
                    break
            elif s[i]=="?":
                s=s[:i-1]+s[i+1:]
                contin=True
                break
    lets=len(s)-1
    for i in range(len(s)):
        if s[i]=="*":
            ind=i
            break
    s=s[:ind]+s[ind-1]*(n-lets)+s[ind+1:]
    print(s)