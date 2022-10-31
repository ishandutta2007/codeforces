ele = 'H,HE,LI,BE,B,C,N,O,F,NE,NA,MG,AL,SI,P,S,CL,AR,K,CA,SC,TI,V,CR,MN,FE,CO,NI,CU,ZN,GA,GE,AS,SE,BR,KR,RB,SR,Y,ZR,NB,MO,TC,RU,RH,PD,AG,CD,IN,SN,SB,TE,I,XE,CS,BA,LA,CE,PR,ND,PM,SM,EU,GD,TB,DY,HO,ER,TM,YB,LU,HF,TA,W,RE,OS,IR,PT,AU,HG,TL,PB,BI,PO,AT,RN,FR,RA,AC,TH,PA,U,NP,PU,AM,CM,BK,CF,ES,FM,MD,NO,LR,RF,DB,SG,BH,HS,MT,DS,RG,CN,NH,FL,MC,LV,TS,OG'.split(',')
has = [input()]
ans = "NO"
while len(has) > 0:
    x = has.pop()
    if x == "":
        ans = "YES"
        break
    if x[0] in ele:
        has.append(x[1:])
    if len(x) > 1 and x[:2] in ele:
        has.append(x[2:])
print(ans)