{$r-,q-,s-,i-,o+}
const
  MAXN=200100;
var
  res:int64;
  kp,xx,yy,n,m,i,j:longint;
  ch:char;
  f1,f2:array[0..200500,'a'..'z']of longint;
  p,s:ansistring;

begin
  readln(m,n);
  readln(s);
  fillchar(f1,sizeof(f1),$0);
  fillchar(f2,sizeof(f2),$0);
  for i:=1 to n do begin
    for ch:='a' to 'z' do f1[i][ch]:=f1[i-1][ch];
    f1[i][s[i]]:=i;
  end;
  for i:=n downto 1 do begin
    for ch:='a' to 'z' do f2[i][ch]:=f2[i+1][ch];
    f2[i][s[i]]:=i;
  end;
  for i:=n+1 to MAXN do 
    for ch:='a' to 'z' do 
      f1[i][ch]:=f1[i-1][ch];
  for i:=1 to m do begin
    readln(p);
    kp:=length(p);
    res:=0;
    for j:=1 to kp do begin
      if (f1[j][p[j]]=0)and(f2[j][p[j]]=0)then begin
        inc(res,kp);continue;
      end;
      xx:=f1[j][p[j]];
      if (xx=0)
        then xx:=maxlongint
        else xx:=abs(xx-j);
      yy:=f2[j][p[j]];
      if (yy=0)
        then yy:=maxlongint
        else yy:=abs(yy-j);
      if (xx<yy)then inc(res,xx) else inc(res,yy);
    end;
    writeln(res);
  end;
end.