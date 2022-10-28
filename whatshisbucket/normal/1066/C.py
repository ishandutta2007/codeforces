n=int(input())
booklist={}
a=input().split()
booklist[a[1]]=0
left=0
right=0
for i in range(n-1):
    a=input().split()
    if a[0]=="L":
        left-=1
        booklist[a[1]]=left
    elif a[0]=="R":
        right+=1
        booklist[a[1]]=right
    else:
        print(min(booklist[a[1]]-left,right-booklist[a[1]]))