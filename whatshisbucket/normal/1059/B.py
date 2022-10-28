n,m=map(int,input().split())
rows=[]
for i in range(n):
    rows.append(input())
copy=rows[:]
for i in range(n-2):
    for j in range(m-2):
        if rows[i][j:j+3]=="###":
            if rows[i+2][j:j+3]=="###":
                if rows[i+1][j]=="#":
                    if rows[i+1][j+2]=="#":
                        copy[i]=copy[i][:j]+"aaa"+copy[i][j+3:]
                        copy[i+1]=copy[i+1][:j]+"a"+copy[i+1][j+1]+"a"+copy[i+1][j+3:]
                        copy[i+2]=copy[i+2][:j]+"aaa"+copy[i+2][j+3:]
done=False
for i in range(n):
    if done:
        break
    for j in range(m):
        if rows[i][j]=="#" and copy[i][j]!="a":
            print("NO")
            done=True
            break
if not done:
    print("YES")