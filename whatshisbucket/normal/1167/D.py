n=int(input())
s=input()
red=0
blue=0
out=""
for char in s:
    if char=="(":
        if red<blue:
            red+=1
            out+="0"
        else:
            blue+=1
            out+="1"
    else:
        if red<blue:
            blue-=1
            out+="1"
        else:
            red-=1
            out+="0"
print(out)