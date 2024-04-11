s=input()
hor=0
vert=0
for i in range(len(s)):
    if s[i]=="0":
        if vert==1:
            vert=0
            print("3 1")
        else:
            vert=1
            print("1 1")
    else:
        hor+=1
        print(hor,2)
        hor%=4