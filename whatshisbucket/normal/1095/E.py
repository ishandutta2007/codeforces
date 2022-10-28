def isregular(s):
    ls=0
    rs=0
    for char in s:
        if char=="(":
            ls+=1
        else:
            rs+=1
        if rs>ls:
            return False
    if ls==rs:
        return True
    return False
n=int(input())
s=input()
if n%2==1:
    print(0)
else:
    a=s.count("(")
    b=n-a
    diff=[0]
    for i in range(n):
        if s[i]=="(":
            diff.append(diff[-1]+1)
        else:
            diff.append(diff[-1]-1)
    if a==b+2:
        if -1 in diff:
            print(0)
        else:
            backdiff=diff[::-1]
            last=backdiff.index(1)
            print(s[-last:].count("("))
    elif b==a+2:
        if -3 in diff:
            print(0)
        else:
            first=diff.index(-1)
            print(s[:first].count(")"))
    else:
        print(0)