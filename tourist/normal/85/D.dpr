{R+,S+,Q+,I+,O-}
{$R-,S-,Q-,I-,O+}
const co = 300;
var
  s: array [0..200010,0..5] of int64;
  rn,a,kind,num,e,pe,c: array [0..200010] of longint;
  q,t,i,tt,qq,ke: longint;
  ans: int64;
  ch,cc: char;

procedure Sort(l,r:longint);
var
  i,j,x,tmp: longint;
begin
  i:=l; j:=r;
  x:=e[l+random(r-l+1)];
  repeat
    while e[i] < x do inc(i);
    while x < e[j] do dec(j);
    if i <= j then
    begin
      tmp:=e[i]; e[i]:=e[j]; e[j]:=tmp;
      tmp:=pe[i]; pe[i]:=pe[j]; pe[j]:=tmp;
      inc(i); dec(j);
    end;
  until i > j;
  if l < j then Sort(l,j);
  if i < r then Sort(i,r);
end;

procedure rebuild(part:longint);
var
  st,fin,q,i: longint;
begin
  st:=(part-1)*co+1;
  fin:=part*co;
  if fin > t then fin:=t;
  for q:=0 to 4 do s[part,q]:=0;
  c[part]:=0;
  q:=2;
  for i:=st to fin do
    if a[i] = 1 then
    begin
      inc(c[part]);
      if c[part] = 5 then c[part]:=0;
      s[part,q]:=s[part,q]+rn[i];
      dec(q);
      if q < 0 then q:=4;
    end;
end;

begin
  randseed:=8753;
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(tt);
  ke:=0;
  for qq:=1 to tt do
  begin
    read(ch);
    while not (ch in ['a'..'z']) do read(ch);
    cc:=ch;
    while ch in ['a'..'z'] do read(ch);
    if cc = 's' then kind[qq]:=0 else
    begin
      if cc = 'a' then kind[qq]:=1
      else kind[qq]:=-1;
      read(num[qq]);
      inc(ke);
      e[ke]:=num[qq];
      pe[ke]:=qq;
    end;
  end;
  if ke > 0 then Sort(1,ke);
  t:=0;
  for i:=1 to ke do
  begin
    if (i = 1) or (e[i] <> e[i-1]) then
    begin
      inc(t);
      rn[t]:=e[i];
    end;
    num[pe[i]]:=t;
  end;
  fillchar(a,sizeof(a),0);
  fillchar(s,sizeof(s),0);
  fillchar(c,sizeof(c),0);
  for qq:=1 to tt do
    if kind[qq] = 0 then
    begin
      ans:=0; q:=0;
      for i:=1 to (t-1) div co+1 do
      begin
        ans:=ans+s[i,q];
        q:=q+c[i];
        if q >= 5 then dec(q,5);
      end;
      writeln(ans);
    end else
    begin
      if kind[qq] = 1 then a[num[qq]]:=1
      else a[num[qq]]:=0;
      rebuild((num[qq]-1) div co+1);
    end;
  close(input);
  close(output);
end.