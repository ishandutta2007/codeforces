{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const cost: array [1..10] of longint = (25,18,15,12,10,8,6,4,2,1);
var
  tt,qq,m,q,n,i,j,km,tmp: longint;
  ok: boolean;
  a: array [0..110,0..110] of longint;
  nam: array [0..110] of ansistring;
  s: ansistring;
begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  readln(tt);
  fillchar(a,sizeof(a),0);
  n:=0;
  for qq:=1 to tt do
  begin
    readln(m);
    for q:=1 to m do
    begin
      readln(s);
      ok:=False;
      for i:=1 to n do
        if nam[i] = s then
        begin
          inc(a[i,q]);
          ok:=True;
          break;
        end;
      if not ok then
      begin
        inc(n);
        nam[n]:=s;
        inc(a[n,q]);
      end;
    end;
  end;
  for i:=1 to n do
    for j:=1 to 10 do inc(a[i,0],a[i,j]*cost[j]);
  for qq:=0 to 1 do
  begin
    km:=1;
    for i:=2 to n do
      for j:=0 to 100 do
        if a[i,j] > a[km,j] then
        begin
          km:=i;
          break;
        end else
        if a[i,j] < a[km,j] then break;
    writeln(nam[km]);
    for i:=1 to n do
    begin
      tmp:=a[i,0];
      a[i,0]:=a[i,1];
      a[i,1]:=tmp;
    end;
  end;
  close(input);
  close(output);
end.