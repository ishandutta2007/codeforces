
#OK the cube is solvable iff :

#2 faces are complete
#4 faces are not
#those 4 faces are in a row
# those 4 faces have a lag of 1
# Hey ! Don't hack me bro !!!


rk=[int(k) for k in raw_input().split(" ")]

faces= [range(k,k+4) for k in range(0,21,4)]

fok=[0]*6

for k in range(6):
    if rk[faces[k][0]]==rk[faces[k][1]] and rk[faces[k][2]]==rk[faces[k][1]] and rk[faces[k][3]]==rk[faces[k][1]]:
        fok[k]=1

if sum(fok)==2 and (fok[0]+fok[2]==2  or fok[1]+fok[5]==2 or fok[3]+fok[4]==2):
    #still can be good
    if fok[0]+fok[2]==2:
        faces= [[4,5,18,19],[16,17,22,23],[20,21,14,15],[12,13,6,7]]
        PotOK=True
        for k in faces:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK=False
        faces2= [[4,5,14,15],[16,17,6,7],[20,21,18,19],[12,13,22,23]]
        PotOK2=True
        for k in faces2:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK2=False
        if PotOK or PotOK2:
            print "YES"
        else:
            print "NO"
    if fok[1]+fok[5]==2:
        faces= [[0,1,16,18],[17,19,8,9],[10,11,13,15],[12,14,2,3]]
        PotOK=True
        for k in faces:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK=False
        faces2= [[0,1,13,15],[17,19,2,3],[10,11,16,18],[12,14,8,9]]
        PotOK2=True
        for k in faces2:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK2=False
        if PotOK or PotOK2:
            print "YES"
        else:
            print "NO"
    if fok[3]+fok[4]==2:
        faces= [[0,2,5,7],[4,6,9,11],[8,10,20,22],[21,23,1,3]]
        PotOK=True
        for k in faces:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK=False
        faces2= [[0,2,20,22],[4,6,1,3],[8,10,5,7],[21,23,9,11]]
        PotOK2=True
        for k in faces2:
            if not (rk[k[0]]==rk[k[1]] and rk[k[0]]==rk[k[2]] and rk[k[0]]==rk[k[1]]):
                PotOK2=False
        if PotOK or PotOK2:
            print "YES"
        else:
            print "NO"


else:
    print "NO"