{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const co = 1439;
var
  ss: ansistring;
  nam: array [0..110] of ansistring;
  ti,f,pr: array [0..110,0..50010] of longint;
  pat,pa,pb,num,cost,tn,t,dl,cd,ct: array [0..50010] of longint;
  gd: array [0..co+10] of boolean;
  km,ans,kp,xx,yy,cnt,n,m,k,i,j,tmp: longint;

procedure readstr(var sl:string);
var
  ch: char;
begin
  read(ch);
  while not (ch in ['a'..'z']) do read(ch);
  sl:='';
  while ch in ['a'..'z'] do
  begin
    sl:=sl+ch;
    read(ch);
  end;
end;

procedure readtime(var xx:longint);
var
  ch,c2,c3,c4,c5: char;
  hh,mm: longint;
begin
  read(ch);
  while not (ch in ['0'..'9']) do read(ch);
  read(c2,c3,c4,c5);
  if c3 <> ':' then hh:=0
  else hh:=(Ord(ch)-48)*10+Ord(c2)-48;
  mm:=(Ord(c4)-48)*10+Ord(c5)-48;
  xx:=hh*60+mm;
end;

procedure writetime(xx:longint);
var
  hh,mm: longint;
begin
  hh:=xx div 60;
  mm:=xx mod 60;
  write(hh div 10,hh mod 10,':',mm div 10,mm mod 10);
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(m,n,k);
  for i:=1 to m do readstr(nam[i]);
  for i:=1 to m do read(tn[i]);
  fillchar(gd,sizeof(gd),True);
  for i:=1 to 4 do
  begin
    readtime(xx);
    readtime(yy);
    for j:=xx to yy do gd[j]:=False;
  end;
  fillchar(ti,sizeof(ti),255);
  cnt:=0;
  for i:=1 to k do
    for j:=0 to co do
    begin
      if gd[j] then
      begin
        inc(cnt);
        cd[cnt]:=i;
        ct[cnt]:=j;
      end;
      ti[i,j]:=cnt;
    end;
  for i:=1 to n do
  begin
    readstr(ss);
    t[i]:=0;
    for j:=1 to m do
      if nam[j] = ss then t[i]:=tn[j];
    read(j);
    readtime(xx);
    if xx > 0 then dl[i]:=ti[j,xx-1]
    else dl[i]:=ti[j-1,co-1];
    read(cost[i]);
    num[i]:=i;
    if t[i] = 0 then dl[i]:=-1;
  end;
  for i:=1 to n-1 do
    for j:=i+1 to n do
      if dl[i] > dl[j] then
      begin
        tmp:=t[i]; t[i]:=t[j]; t[j]:=tmp;
        tmp:=dl[i]; dl[i]:=dl[j]; dl[j]:=tmp;
        tmp:=cost[i]; cost[i]:=cost[j]; cost[j]:=tmp;
        tmp:=num[i]; num[i]:=num[j]; num[j]:=tmp;
      end;
  fillchar(f,sizeof(f),200);
  fillchar(pr,sizeof(pr),0);
  f[1,0]:=0;
  for i:=1 to n do
    for j:=0 to cnt do
    begin
      if f[i,j] > f[i+1,j] then
      begin
        f[i+1,j]:=f[i,j];
        pr[i+1,j]:=0;
      end;
      if (j+t[i] <= dl[i]) and (f[i,j]+cost[i] > f[i+1,j+t[i]]) then
      begin
        f[i+1,j+t[i]]:=f[i,j]+cost[i];
        pr[i+1,j+t[i]]:=1;
      end;
    end;
  ans:=-1; km:=0;
  for j:=0 to cnt do
    if f[n+1,j] > ans then
    begin
      ans:=f[n+1,j];
      km:=j;
    end;
  writeln(ans);
  kp:=0; j:=km;
  for i:=n+1 downto 2 do
    if pr[i,j] = 1 then
    begin
      inc(kp);
      pat[kp]:=num[i-1];
      pa[kp]:=j-t[i-1]+1;
      pb[kp]:=j;
      dec(j,t[i-1]);
    end;
  writeln(kp);
  for i:=kp downto 1 do
  begin
    write(pat[i],' ',cd[pa[i]],' ');
    writetime(ct[pa[i]]);
    write(' ',cd[pb[i]],' ');
    writetime(ct[pb[i]]);
    writeln;
  end;
  close(input);
  close(output);
end.