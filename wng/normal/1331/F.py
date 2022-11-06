els=set(['H','HE','LI','BE','B','C','N','O','F','NE','NA','MG','AL','SI','P','S','CL','AR','K','CA','SC','TI','V','CR','MN','FE','CO','NI','CU','ZN','GA','GE','AS','SE','BR','KR','RB','SR','Y','ZR','NB','MO','TC','RU','RH','PD','AG','CD','IN','SN','SB','TE','I','XE','CS','BA','LA','CE','PR','ND','PM','SM','EU','GD','TB','DY','HO','ER','TM','YB','LU','HF','TA','W','RE','OS','IR','PT','AU','HG','TL','PB','BI','PO','AT','RN','FR','RA','AC','TH','PA','U','NP','PU','AM','CM','BK','CF','ES','FM','MD','NO','LR','RF','DB','SG','BH','HS','MT','DS','RG','CN','NH','FL','MC','LV','TS','OG','UUE','UBN','UBU','UBB','UBT','UBQ','UBP','UBH'])

i=input()


a=[1]+[0]*len(i)
for j in range(len(i)):
    if i[j] in els:
        a[j+1]=max(a[j+1],a[j])
    if j and i[j-1:j+1] in els:
        a[j+1]=max(a[j+1],a[j-1])

if a[-1]:
    print("YES")
else:
    print("NO")