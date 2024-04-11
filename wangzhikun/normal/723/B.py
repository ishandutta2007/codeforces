length = int(input())
string = input()
ans1=0
ans2=0
def ischar(a):
    ret = False
    if a>="a" and a<="z":
        ret = True
    if a>="A" and a<="Z":
        ret = True
    return ret
str_start = 1000
in_par = 0
length+=1
string+="_"
for i in range(length):
    if string[i] == "(":
        in_par = 1
        ans1=max(ans1,i-str_start)
        str_start = 1000
    if string[i] == ")":
        in_par = 0
        if i>str_start:
            ans2+=1
            str_start = 1000
    if in_par:
        if ischar(string[i]):
            str_start = min(i,str_start)
        if string[i] == '_' and i>str_start:
            ans2+=1
            str_start = 1000
    else:
        if ischar(string[i]):
            str_start = min(i,str_start)
        if string[i] == '_':
            ans1=max(ans1,i-str_start)
            str_start = 1000
print(str(ans1)+" "+str(ans2))