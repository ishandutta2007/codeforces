{$r-,q-,s-,i-,o+}
const
  kol:array[1..12]of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
 
var
  p,s,sd,sm,sy:ansistring;
  max,mm,dd,tm,td,ty,yy,i,j:longint;
  kq:array[1..55,0..55,0..55]of longint;
  bad:boolean;

begin
  readln(s);
  for i:=1 to length(s)-9 do begin
    p:='';
    for j:=i to i+9 do p:=p+s[j];
    bad:=false;
    for j:=1 to 10 do begin
      if (p[j]='-')and(j<>3)and(j<>6)then begin
        bad:=true;
        break;
      end;
      if ((j=3)or(j=6))and(p[j]<>'-')then begin
        bad:=true;
        break;
      end;
    end;
    if (bad)then continue;
    val(copy(p,1,2),dd);
    val(copy(p,4,2),mm);
    val(copy(p,7,4),yy);
    if (yy<2013)then continue;
    if (yy>2015)then continue;
    if (mm<1)then continue;
    if (mm>12)then continue;
    if (dd<1)then continue;
    if (dd>kol[mm])then continue;
    inc(kq[yy-2012][mm][dd]);
  end;
  for yy:=1 to 3 do
    for mm:=1 to 12 do 
      for dd:=1 to kol[mm] do 
        if (kq[yy][mm][dd]>max)then begin
          max:=kq[yy][mm][dd];
          ty:=yy;
          tm:=mm;
          td:=dd;
        end;
  str(ty+2012,sy);
  str(tm,sm);
  while (length(sm)<2)do sm:='0'+sm;
  str(td,sd);
  while (length(sd)<2)do sd:='0'+sd;
  writeln(sd,'-',sm,'-',sy);
end.