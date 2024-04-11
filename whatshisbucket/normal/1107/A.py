q=int(input())
for u in range(q):
    n=int(input())
    s=input()
    if len(s)==2 and int(s[0])>=int(s[1]):
        print("NO")
    else:
        print("YES")
        print(2)
        print(s[0],s[1:])