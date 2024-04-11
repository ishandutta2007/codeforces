{$R+,S+,Q+,I+,O-}
var
  n,m: longint;
begin
  read(n,m);
  if (n = 1) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
  end;
  if (n = 1) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
  end;
  if (n = 1) and (m = 3) then
  begin
    writeln(0);
    writeln('...');
  end;
  if (n = 1) and (m = 4) then
  begin
    writeln(0);
    writeln('....');
  end;
  if (n = 1) and (m = 5) then
  begin
    writeln(0);
    writeln('.....');
  end;
  if (n = 1) and (m = 6) then
  begin
    writeln(0);
    writeln('......');
  end;
  if (n = 1) and (m = 7) then
  begin
    writeln(0);
    writeln('.......');
  end;
  if (n = 1) and (m = 8) then
  begin
    writeln(0);
    writeln('........');
  end;
  if (n = 1) and (m = 9) then
  begin
    writeln(0);
    writeln('.........');
  end;
  if (n = 2) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
  end;
  if (n = 2) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
  end;
  if (n = 2) and (m = 3) then
  begin
    writeln(0);
    writeln('...');
    writeln('...');
  end;
  if (n = 2) and (m = 4) then
  begin
    writeln(0);
    writeln('....');
    writeln('....');
  end;
  if (n = 2) and (m = 5) then
  begin
    writeln(0);
    writeln('.....');
    writeln('.....');
  end;
  if (n = 2) and (m = 6) then
  begin
    writeln(0);
    writeln('......');
    writeln('......');
  end;
  if (n = 2) and (m = 7) then
  begin
    writeln(0);
    writeln('.......');
    writeln('.......');
  end;
  if (n = 2) and (m = 8) then
  begin
    writeln(0);
    writeln('........');
    writeln('........');
  end;
  if (n = 2) and (m = 9) then
  begin
    writeln(0);
    writeln('.........');
    writeln('.........');
  end;
  if (n = 3) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 3) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 3) and (m = 3) then
  begin
    writeln(1);
    writeln('AAA');
    writeln('.A.');
    writeln('.A.');
  end;
  if (n = 3) and (m = 4) then
  begin
    writeln(1);
    writeln('AAA.');
    writeln('.A..');
    writeln('.A..');
  end;
  if (n = 3) and (m = 5) then
  begin
    writeln(2);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('.ABBB');
  end;
  if (n = 3) and (m = 6) then
  begin
    writeln(2);
    writeln('AAABBB');
    writeln('.A..B.');
    writeln('.A..B.');
  end;
  if (n = 3) and (m = 7) then
  begin
    writeln(3);
    writeln('AAABCCC');
    writeln('.A.B.C.');
    writeln('.ABBBC.');
  end;
  if (n = 3) and (m = 8) then
  begin
    writeln(3);
    writeln('AAABBBC.');
    writeln('.A..B.C.');
    writeln('.A..BCCC');
  end;
  if (n = 3) and (m = 9) then
  begin
    writeln(4);
    writeln('AAABCCCD.');
    writeln('.A.B.C.D.');
    writeln('.ABBBCDDD');
  end;
  if (n = 4) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 4) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 4) and (m = 3) then
  begin
    writeln(1);
    writeln('AAA');
    writeln('.A.');
    writeln('.A.');
    writeln('...');
  end;
  if (n = 4) and (m = 4) then
  begin
    writeln(2);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('.BBB');
  end;
  if (n = 4) and (m = 5) then
  begin
    writeln(2);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('.ABBB');
    writeln('.....');
  end;
  if (n = 4) and (m = 6) then
  begin
    writeln(3);
    writeln('AAABBB');
    writeln('.AC.B.');
    writeln('.AC.B.');
    writeln('.CCC..');
  end;
  if (n = 4) and (m = 7) then
  begin
    writeln(4);
    writeln('AAABBB.');
    writeln('.AC.BD.');
    writeln('.AC.BD.');
    writeln('.CCCDDD');
  end;
  if (n = 4) and (m = 8) then
  begin
    writeln(4);
    writeln('AAABBBC.');
    writeln('.AD.B.C.');
    writeln('.AD.BCCC');
    writeln('.DDD....');
  end;
  if (n = 4) and (m = 9) then
  begin
    writeln(5);
    writeln('AAABBBCCC');
    writeln('.AD.BE.C.');
    writeln('.AD.BE.C.');
    writeln('.DDDEEE..');
  end;
  if (n = 5) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 5) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 5) and (m = 3) then
  begin
    writeln(2);
    writeln('AAA');
    writeln('.A.');
    writeln('BA.');
    writeln('BBB');
    writeln('B..');
  end;
  if (n = 5) and (m = 4) then
  begin
    writeln(2);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('.BBB');
    writeln('....');
  end;
  if (n = 5) and (m = 5) then
  begin
    writeln(4);
    writeln('AAA.B');
    writeln('.ABBB');
    writeln('CA.DB');
    writeln('CCCD.');
    writeln('C.DDD');
  end;
  if (n = 5) and (m = 6) then
  begin
    writeln(4);
    writeln('AAABBB');
    writeln('.A..B.');
    writeln('CA.DB.');
    writeln('CCCDDD');
    writeln('C..D..');
  end;
  if (n = 5) and (m = 7) then
  begin
    writeln(5);
    writeln('AAABBB.');
    writeln('.A..BC.');
    writeln('DA.EBC.');
    writeln('DDDECCC');
    writeln('D.EEE..');
  end;
  if (n = 5) and (m = 8) then
  begin
    writeln(6);
    writeln('AAABBB.C');
    writeln('.A..BCCC');
    writeln('DA.EB.FC');
    writeln('DDDEEEF.');
    writeln('D..E.FFF');
  end;
  if (n = 5) and (m = 9) then
  begin
    writeln(7);
    writeln('AAABBBC..');
    writeln('.A..BDCCC');
    writeln('EA.FBDCG.');
    writeln('EEEFDDDG.');
    writeln('E.FFF.GGG');
  end;
  if (n = 6) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 6) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 6) and (m = 3) then
  begin
    writeln(2);
    writeln('AAA');
    writeln('.A.');
    writeln('BA.');
    writeln('BBB');
    writeln('B..');
    writeln('...');
  end;
  if (n = 6) and (m = 4) then
  begin
    writeln(3);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('CBBB');
    writeln('CCC.');
    writeln('C...');
  end;
  if (n = 6) and (m = 5) then
  begin
    writeln(4);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('CABBB');
    writeln('CCCD.');
    writeln('CDDD.');
    writeln('...D.');
  end;
  if (n = 6) and (m = 6) then
  begin
    writeln(5);
    writeln('AAABBB');
    writeln('.AC.B.');
    writeln('.AC.B.');
    writeln('DCCCE.');
    writeln('DDD.E.');
    writeln('D..EEE');
  end;
  if (n = 6) and (m = 7) then
  begin
    writeln(6);
    writeln('AAAB...');
    writeln('.ACBBBD');
    writeln('.ACBDDD');
    writeln('ECCCF.D');
    writeln('EEE.FFF');
    writeln('E...F..');
  end;
  if (n = 6) and (m = 8) then
  begin
    writeln(7);
    writeln('AAABBBC.');
    writeln('.AD.B.C.');
    writeln('.AD.BCCC');
    writeln('EDDDFGGG');
    writeln('EEE.F.G.');
    writeln('E..FFFG.');
  end;
  if (n = 6) and (m = 9) then
  begin
    writeln(8);
    writeln('AAABBBCCC');
    writeln('.AD.B.EC.');
    writeln('.AD.B.EC.');
    writeln('FDDDGEEEH');
    writeln('FFF.G.HHH');
    writeln('F..GGG..H');
  end;
  if (n = 7) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 7) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 7) and (m = 3) then
  begin
    writeln(3);
    writeln('AAA');
    writeln('.A.');
    writeln('BA.');
    writeln('BBB');
    writeln('BC.');
    writeln('.C.');
    writeln('CCC');
  end;
  if (n = 7) and (m = 4) then
  begin
    writeln(4);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('CBBB');
    writeln('CCCD');
    writeln('CDDD');
    writeln('...D');
  end;
  if (n = 7) and (m = 5) then
  begin
    writeln(5);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('CABBB');
    writeln('CCCD.');
    writeln('CE.D.');
    writeln('.EDDD');
    writeln('EEE..');
  end;
  if (n = 7) and (m = 6) then
  begin
    writeln(6);
    writeln('AAABBB');
    writeln('.A..B.');
    writeln('CA.DB.');
    writeln('CCCDDD');
    writeln('CE.DF.');
    writeln('.EEEF.');
    writeln('.E.FFF');
  end;
  if (n = 7) and (m = 7) then
  begin
    writeln(8);
    writeln('AAABCCC');
    writeln('.A.B.C.');
    writeln('DABBBCE');
    writeln('DDDFEEE');
    writeln('DG.F.HE');
    writeln('.GFFFH.');
    writeln('GGG.HHH');
  end;
  if (n = 7) and (m = 8) then
  begin
    writeln(9);
    writeln('AAA.BBB.');
    writeln('.ACCCBD.');
    writeln('.AEC.BD.');
    writeln('EEECFDDD');
    writeln('G.EHFFFI');
    writeln('GGGHFIII');
    writeln('G.HHH..I');
  end;
  if (n = 7) and (m = 9) then
  begin
    writeln(10);
    writeln('AAAB..CCC');
    writeln('.ADBBB.C.');
    writeln('.ADBEEECF');
    writeln('GDDD.EFFF');
    writeln('GGGHIE.JF');
    writeln('GHHHIIIJ.');
    writeln('...HI.JJJ');
  end;
  if (n = 8) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 8) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 8) and (m = 3) then
  begin
    writeln(3);
    writeln('AAA');
    writeln('.A.');
    writeln('BA.');
    writeln('BBB');
    writeln('BC.');
    writeln('.C.');
    writeln('CCC');
    writeln('...');
  end;
  if (n = 8) and (m = 4) then
  begin
    writeln(4);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('CBBB');
    writeln('CCCD');
    writeln('CDDD');
    writeln('...D');
    writeln('....');
  end;
  if (n = 8) and (m = 5) then
  begin
    writeln(6);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('CABBB');
    writeln('CCCD.');
    writeln('CDDD.');
    writeln('EEEDF');
    writeln('.EFFF');
    writeln('.E..F');
  end;
  if (n = 8) and (m = 6) then
  begin
    writeln(7);
    writeln('AAABBB');
    writeln('.AC.B.');
    writeln('.AC.B.');
    writeln('DCCC.E');
    writeln('DDDEEE');
    writeln('DFFFGE');
    writeln('..F.G.');
    writeln('..FGGG');
  end;
  if (n = 8) and (m = 7) then
  begin
    writeln(9);
    writeln('AAAB...');
    writeln('.ACBBBD');
    writeln('.ACBDDD');
    writeln('ECCCF.D');
    writeln('EEEGFFF');
    writeln('EH.GFI.');
    writeln('.HGGGI.');
    writeln('HHH.III');
  end;
  if (n = 8) and (m = 8) then
  begin
    writeln(10);
    writeln('AAABBBC.');
    writeln('.A..B.C.');
    writeln('DA..BCCC');
    writeln('DDDEEE.F');
    writeln('DGGGEFFF');
    writeln('.HGIE.JF');
    writeln('.HGIIIJ.');
    writeln('HHHI.JJJ');
  end;
  if (n = 8) and (m = 9) then
  begin
    writeln(12);
    writeln('AAABBB..C');
    writeln('.AD.BECCC');
    writeln('.AD.BEEEC');
    writeln('FDDDGEHHH');
    writeln('FFFIGGGH.');
    writeln('FJ.IGK.HL');
    writeln('.JIIIKLLL');
    writeln('JJJ.KKK.L');
  end;
  if (n = 9) and (m = 1) then
  begin
    writeln(0);
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
    writeln('.');
  end;
  if (n = 9) and (m = 2) then
  begin
    writeln(0);
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
    writeln('..');
  end;
  if (n = 9) and (m = 3) then
  begin
    writeln(4);
    writeln('AAA');
    writeln('.A.');
    writeln('BA.');
    writeln('BBB');
    writeln('B.C');
    writeln('CCC');
    writeln('D.C');
    writeln('DDD');
    writeln('D..');
  end;
  if (n = 9) and (m = 4) then
  begin
    writeln(5);
    writeln('AAA.');
    writeln('.AB.');
    writeln('.AB.');
    writeln('CBBB');
    writeln('CCCD');
    writeln('CDDD');
    writeln('EEED');
    writeln('.E..');
    writeln('.E..');
  end;
  if (n = 9) and (m = 5) then
  begin
    writeln(7);
    writeln('AAAB.');
    writeln('.A.B.');
    writeln('CABBB');
    writeln('CCC.D');
    writeln('CEDDD');
    writeln('.EEED');
    writeln('FEGGG');
    writeln('FFFG.');
    writeln('F..G.');
  end;
  if (n = 9) and (m = 6) then
  begin
    writeln(8);
    writeln('AAABBB');
    writeln('.AC.B.');
    writeln('.AC.B.');
    writeln('DCCCE.');
    writeln('DDD.E.');
    writeln('D.FEEE');
    writeln('.GFFFH');
    writeln('.GFHHH');
    writeln('GGG..H');
  end;
  if (n = 9) and (m = 7) then
  begin
    writeln(10);
    writeln('AAABBB.');
    writeln('.A..BC.');
    writeln('DA.EBC.');
    writeln('DDDECCC');
    writeln('DFEEE.G');
    writeln('.FFFGGG');
    writeln('HFIIIJG');
    writeln('HHHI.J.');
    writeln('H..IJJJ');
  end;
  if (n = 9) and (m = 8) then
  begin
    writeln(12);
    writeln('A..FFF.J');
    writeln('AAADFJJJ');
    writeln('ADDDF.IJ');
    writeln('B..DIII.');
    writeln('BBBGGGIK');
    writeln('BEEEGKKK');
    writeln('.CEHG.LK');
    writeln('.CEHHHL.');
    writeln('CCCH.LLL');
  end;
  if (n = 9) and (m = 9) then
  begin
    writeln(13);
    writeln('AAABBBCCC');
    writeln('.AD.BE.C.');
    writeln('.AD.BE.C.');
    writeln('FDDDEEE.G');
    writeln('FFFHHHGGG');
    writeln('FIIIHJJJG');
    writeln('.KILH.JM.');
    writeln('.KILLLJM.');
    writeln('KKKL..MMM');
  end;
end.