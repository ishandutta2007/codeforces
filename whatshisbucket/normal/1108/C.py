n=int(input())
s=input()
rgb=n
rbg=n
grb=n
gbr=n
brg=n
bgr=n
for i in range(n):
    if i%3==0:
        if s[i]=="R":
            rgb-=1
            rbg-=1
        elif s[i]=="G":
            grb-=1
            gbr-=1
        else:
            brg-=1
            bgr-=1
    elif i%3==1:
        if s[i]=="R":
            grb-=1
            brg-=1
        elif s[i]=="G":
            rgb-=1
            bgr-=1
        else:
            rbg-=1
            gbr-=1
    else:
        if s[i]=="R":
            gbr-=1
            bgr-=1
        elif s[i]=="G":
            rbg-=1
            brg-=1
        else:
            rgb-=1
            grb-=1
sml=min([rgb,rbg,grb,gbr,brg,bgr])
print(sml)
if rgb==sml:
    print("RGB"*(n//3)+"RGB"[:n%3])
elif rbg==sml:
    print("RBG"*(n//3)+"RBG"[:n%3])
elif grb==sml:
    print("GRB"*(n//3)+"GRB"[:n%3])
elif gbr==sml:
    print("GBR"*(n//3)+"GBR"[:n%3])
elif brg==sml:
    print("BRG"*(n//3)+"BRG"[:n%3])
else:
    print("BGR"*(n//3)+"BGR"[:n%3])