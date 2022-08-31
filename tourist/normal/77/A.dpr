{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
var
  n,ans,km,i,x,y,qa,qb,qc: longint;
  aa: array [0..9,0..9] of longint;
  bb: array [0..9] of longint;

procedure rec(v,a,b,c:longint);
var
  ca,cb,cc,min,max,cur,cm,i,j: longint;
begin
  if v = 8 then
  begin
    if a*b*c = 0 then exit;
    ca:=qa div a;
    cb:=qb div b;
    cc:=qc div c;
    min:=ca;
    if cb < min then min:=cb;
    if cc < min then min:=cc;
    max:=ca;
    if cb > max then max:=cb;
    if cc > max then max:=cc;
    cur:=max-min;
    cm:=0;
    for i:=1 to 7 do
      for j:=1 to 7 do
        if (aa[i,j] = 1) and (bb[i] = bb[j]) then inc(cm);
    if (cur < ans) or (cur = ans) and (cm > km) then
    begin
      ans:=cur;
      km:=cm;
    end;
    exit;
  end;
  bb[v]:=1;
  rec(v+1,a+1,b,c);
  bb[v]:=2;
  rec(v+1,a,b+1,c);
  bb[v]:=3;
  rec(v+1,a,b,c+1);
  bb[v]:=0;
end;

function get():longint;
var
  ch: char;
  nam: ansistring;
begin
  read(ch);
  while not (ch in ['A'..'Z']) do read(ch);
  nam:='';
  while ch in ['A'..'Z','a'..'z'] do
  begin
    nam:=nam+ch;
    read(ch);
  end;
  if nam = 'Dracul' then get:=1 else
  if nam = 'Troll' then get:=2 else
  if nam = 'Anka' then get:=3 else
  if nam = 'Hexadecimal' then get:=4 else
  if nam = 'Snowy' then get:=5 else
  if nam = 'Cleo' then get:=6 else
  if nam = 'Chapay' then get:=7
  else get:=0;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(n);
  fillchar(aa,sizeof(aa),0);
  for i:=1 to n do
  begin
    x:=get();
    y:=get();
    aa[x,y]:=1;
  end;
  read(qa,qb,qc);
  ans:=maxlongint;
  km:=0;
  rec(1,0,0,0);
  writeln(ans,' ',km);
  close(input);
  close(output);
end.