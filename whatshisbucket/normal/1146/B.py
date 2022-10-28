s=input()
l=len(s)
a=s.count("a")
if (l+a)%2==1:
    print(":(")
else:
    og=s[:(l+a)//2]
    newg=""
    for char in og:
        if char!="a":
            newg+=char
    if newg==s[(l+a)//2:]:
        print(og)
    else:
        print(":(")