a,b=map(int,input().split())
s1=str(input())
s2=str(input())
try:
    l=s1.index("*")
    if(s1[0:l:1]==s2[0:l:1] and s1[(-1):(-len(s1)+l):(-1)]==s2[(-1):(-len(s1)+l):(-1)]):
        if(len(s2)>=len(s1)-1):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
except:
    if(s1==s2):
        print("YES")
    else:
        print("NO")