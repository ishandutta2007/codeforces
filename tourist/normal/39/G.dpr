{$R+,S+,Q+,I+,O-}
{R-,S-,Q-,I-,O+}
const LESS = -1; EQUAL = 0; MORE = 1;
type TMult = record
               kind,num,expid: longint;
             end;
     TProd = record
               sign: boolean;
               cm: longint;
               sn: array [0..110] of boolean;
               m: array [0..110] of TMult;
             end;
     TExpr = record
               cp: longint;
               p: array [0..110] of TProd;
             end;
var
  sl,st: ansistring;
  z,mm,ps,pz,need,ans,kc,i,n: longint;
  left,right,sign,return: array [0..1010] of longint;
  f: array [0..33333] of longint;
  c: array [0..1010] of char;
  exp: array [0..110] of TExpr;
  ch: char;
  can: boolean;

function makeexpr(s:ansistring):longint;
var
  m,q,i,v,t,bal: longint;
  ss: ansistring;
begin
  inc(mm); m:=mm;
  exp[m].cp:=0;
  s:='+'+s+'+';
  i:=1;
  while i < length(s) do
  begin
    inc(exp[m].cp);
    v:=exp[m].cp;
    exp[m].p[v].sign:=s[i] = '-';
    exp[m].p[v].cm:=0;
    s[i]:='*';
    while (s[i] = '*') or (s[i] = '/') do
    begin
      inc(exp[m].p[v].cm);
      t:=exp[m].p[v].cm;
      exp[m].p[v].sn[t]:=s[i] = '/';
      if s[i+1] = 'n' then
      begin
        exp[m].p[v].m[t].kind:=1;
        inc(i,2);
      end else
      if s[i+1] = 'f' then
      begin
        exp[m].p[v].m[t].kind:=3;
        ss:=''; bal:=1;
        inc(i,3);
        while bal > 0 do
        begin
          if s[i] = '(' then inc(bal) else
          if s[i] = ')' then dec(bal);
          if bal = 0 then break;
          ss:=ss+s[i];
          inc(i);
        end;
        exp[m].p[v].m[t].expid:=makeexpr(ss);
        inc(i);
      end else
      begin
        exp[m].p[v].m[t].kind:=2;
        q:=0; inc(i);
        while s[i] in ['0'..'9'] do
        begin
          q:=q*10+Ord(s[i])-48;
          inc(i);
        end;
        exp[m].p[v].m[t].num:=q;
      end;
    end;
  end;
  makeexpr:=m;
end;

function eval(m,z:longint):longint;
var
  res,i,j,cur,v: longint;
begin
  res:=0;
  for i:=1 to exp[m].cp do
  begin
    cur:=1;
    for j:=1 to exp[m].p[i].cm do
    begin
      if exp[m].p[i].m[j].kind = 1 then v:=z else
      if exp[m].p[i].m[j].kind = 2 then v:=exp[m].p[i].m[j].num
      else v:=f[eval(exp[m].p[i].m[j].expid,z)];
      if exp[m].p[i].sn[j] then cur:=cur div v
      else cur:=(cur*v) mod 32768;
    end;
    if exp[m].p[i].sign then cur:=-cur;
    inc(res,cur);
    if res >= 32768 then dec(res,32768);
    if res < 0 then inc(res,32768);
  end;
  eval:=res;
end;

function get(z:longint):longint;
var
  i,zleft,zright: longint;
begin
  for i:=1 to n do
  begin
    zleft:=eval(left[i],z);
    zright:=eval(right[i],z);
    if (sign[i] = LESS)  and (zleft < zright) or
       (sign[i] = EQUAL) and (zleft = zright) or
       (sign[i] = MORE)  and (zleft > zright) then
    begin
      get:=eval(return[i],z);
      exit;
    end;
  end;
  get:=0;
end;

begin
//  assign(input,'in'); reset(input);
//  assign(output,'out'); rewrite(output);
  read(need);
  kc:=0; can:=False;
  while not eof(input) do
  begin
    read(ch);
    if (ch = ' ') or (ch = #9) or (ch = #13) or (ch = #10) then continue;
    if ch = '{' then can:=True else
    if ch = '}' then can:=False else
    if can then
    begin
      inc(kc);
      c[kc]:=ch;
    end;
  end;
  sl:=''; n:=0;
  mm:=1;
  exp[1].cp:=1;
  exp[1].p[1].sign:=False;
  exp[1].p[1].cm:=1;
  exp[1].p[1].m[1].kind:=2;
  exp[1].p[1].m[1].num:=0;
  for i:=1 to kc do
    if c[i] = ';' then
    begin
      inc(n);
      ps:=Pos('r',sl);
      if ps = 1 then
      begin
        left[n]:=1;
        right[n]:=1;
        sign[n]:=EQUAL;
      end else
      begin
        st:=Copy(sl,4,ps-5);
        pz:=Pos('<',st);
        if pz > 0 then sign[n]:=LESS else
        begin
          pz:=Pos('>',st);
          if pz > 0 then sign[n]:=MORE else
          begin
            pz:=Pos('=',st);
            Delete(st,pz,1);
            sign[n]:=EQUAL;
          end;
        end;
        left[n]:=makeexpr(Copy(st,1,pz-1));
        right[n]:=makeexpr(Copy(st,pz+1,1000));
        Delete(sl,1,ps-1);
      end;
      return[n]:=makeexpr(Copy(sl,7,1000));
      sl:='';
    end
    else sl:=sl+c[i];
  ans:=-1;
  for z:=0 to 32767 do
  begin
    f[z]:=get(z);
    if f[z] = need then ans:=z;
  end;
  writeln(ans);
  close(input);
  close(output);
end.