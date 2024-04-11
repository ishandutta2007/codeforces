a=input()
b=input()
c=input()
d=input()
e=input()
list=[a,b,c,d,e]
for i in range(5):
    for j in range(9):
        if list[i][j]=="1":
            print(abs(i-2)+abs((j+2)//2-3))